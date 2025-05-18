#include "tsp.h"
#include "ui_tsp.h"
#include <QInputDialog>
#include <QMessageBox>
#include <algorithm>
#include <cmath>

TSP::TSP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TSP)
    , scene(new QGraphicsScene(this))
    , totalCost(0)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(Qt::white);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->viewport()->installEventFilter(this);
    ui->graphicsView->setSceneRect(0, 0, 800, 600);
    ui->resultLabel->setWordWrap(true);
}

TSP::~TSP()
{
    delete ui;
}

bool TSP::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->graphicsView->viewport() && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            QPointF scenePos = ui->graphicsView->mapToScene(mouseEvent->pos());
            addVertexAtPosition(scenePos);
            return true;
        }
    }
    return QMainWindow::eventFilter(watched, event);
}

void TSP::on_addVertexButton_clicked()
{
    ui->resultLabel->setText("Кликните на сцену, чтобы разместить вершину");
    ui->graphicsView->setMouseTracking(true);
}

void TSP::addVertexAtPosition(const QPointF &pos)
{
    if (isOverlapping(pos.x(), pos.y(), 40)) {
        QMessageBox::warning(this, "Ошибка", "Вершины слишком близко друг к другу!");
        return;
    }

    QGraphicsEllipseItem *vertex = scene->addEllipse(0, 0, 30, 30, QPen(Qt::black), QBrush(Qt::lightGray));
    vertex->setPos(pos.x() - 15, pos.y() - 15);

    QGraphicsTextItem *label = scene->addText(QString::number(vertices.size() + 1));
    label->setPos(vertex->pos() + QPointF(15 - label->boundingRect().width()/2,
                                          15 - label->boundingRect().height()/2));
    label->setDefaultTextColor(Qt::black);

    vertices.append(vertex);
    adjacencyMatrix.resize(vertices.size());
    for (auto &row : adjacencyMatrix) {
        row.resize(vertices.size(), INT_MAX);
    }
}

void TSP::on_addEdgeButton_clicked()
{
    if (vertices.size() < 2) {
        QMessageBox::warning(this, "Ошибка", "Нужно минимум 2 вершины!");
        return;
    }

    QStringList vertexList;
    for (int i = 0; i < vertices.size(); ++i) {
        vertexList << QString::number(i + 1);
    }

    bool ok;
    QString from = QInputDialog::getItem(this, "Выберите вершину", "От:", vertexList, 0, false, &ok);
    if (!ok) return;

    QString to = QInputDialog::getItem(this, "Выберите вершину", "До:", vertexList, 1, false, &ok);
    if (!ok || from == to) {
        QMessageBox::warning(this, "Ошибка", "Выберите разные вершины!");
        return;
    }

    int cost = QInputDialog::getInt(this, "Стоимость", "Введите стоимость:", 1, 1, 1000, 1, &ok);
    if (!ok) return;

    int fromIdx = from.toInt() - 1;
    int toIdx = to.toInt() - 1;

    adjacencyMatrix[fromIdx][toIdx] = cost;
    adjacencyMatrix[toIdx][fromIdx] = cost;

    // Получаем позиции центров вершин
    QPointF fromCenter = vertices[fromIdx]->pos() + QPointF(15, 15);
    QPointF toCenter = vertices[toIdx]->pos() + QPointF(15, 15);

    // Вычисляем вектор направления
    QPointF direction = toCenter - fromCenter;
    qreal length = sqrt(direction.x() * direction.x() + direction.y() * direction.y());

    if (length > 0) {
        // Нормализуем вектор и укорачиваем на радиус вершины (15px)
        QPointF normalized = direction / length;
        QPointF startPoint = fromCenter + normalized * 15;
        QPointF endPoint = toCenter - normalized * 15;

        // Создаем линию
        QLineF line(startPoint, endPoint);
        QGraphicsLineItem *edge = scene->addLine(line, QPen(Qt::blue, 2));
        edge->setZValue(1); // Помещаем ребро под текст

        // Добавляем текст со стоимостью
        QGraphicsTextItem *costLabel = scene->addText(QString::number(cost));
        costLabel->setPos(line.center());
        costLabel->setDefaultTextColor(Qt::darkBlue);
        costLabel->setZValue(2); // Текст поверх ребра

        // Сохраняем информацию о рёбрах и тексте стоимости
        selectedEdges.append(qMakePair(fromIdx, toIdx));
        selectedEdgeItems.append(edge);  // Сохраняем ребро
        selectedEdgeLabels.append(costLabel);  // Сохраняем текст стоимости
    }
}


void TSP::on_solveButton_clicked()
{
    if (vertices.size() < 2) {
        QMessageBox::warning(this, "Ошибка", "Добавьте минимум 2 вершины!");
        return;
    }

    // Удаляем предыдущее выделение пути
    for (auto item : scene->items()) {
        if (item->data(0).toString() == "path") {
            scene->removeItem(item);
            delete item;
        }
    }

    // Базовый случай для 2 вершин
    if (vertices.size() == 2) {
        int cost = adjacencyMatrix[0][1];
        if (cost == INT_MAX) {
            ui->resultLabel->setText("Нет пути между вершинами!");
            return;
        }
        ui->resultLabel->setText(QString("Оптимальный маршрут: 1 → 2 → 1\nСтоимость: %1").arg(2 * cost));
        return;
    }

    QVector<int> vertexIndices;
    for (int i = 0; i < vertices.size(); ++i) {
        vertexIndices.append(i);
    }

    int minCost = INT_MAX;
    QVector<int> bestPath;

    do {
        int currentCost = 0;
        bool validPath = true;

        // Считаем стоимость
        for (int i = 0; i < vertexIndices.size(); ++i) {
            int from = vertexIndices[i];
            int to = vertexIndices[(i + 1) % vertexIndices.size()];

            if (adjacencyMatrix[from][to] == INT_MAX) {
                validPath = false;
                break;
            }
            currentCost += adjacencyMatrix[from][to];
        }

        if (validPath && currentCost < minCost) {
            minCost = currentCost;
            bestPath = vertexIndices;
        }
    } while (std::next_permutation(vertexIndices.begin(), vertexIndices.end()));

    if (bestPath.isEmpty()) {
        ui->resultLabel->setText("Нет возможного маршрута!");
        return;
    }

    // Формируем строку результата
    QString result = "Оптимальный маршрут: ";
    for (int i = 0; i < bestPath.size(); ++i) {
        if (i != 0) result += " → ";
        result += QString::number(bestPath[i] + 1);
    }
    // Добавляем возврат в начальную вершину
    result += QString(" → %1").arg(bestPath[0] + 1);
    result += QString("\nСтоимость: %1").arg(minCost);

    ui->resultLabel->setText(result);
}

QVector<QVector<int>> TSP::reduceMatrix(QVector<QVector<int>> matrix, int &reductionCost)
{
    // Редукция строк
    for (int i = 0; i < matrix.size(); ++i) {
        int minVal = INT_MAX;
        // Находим минимальный элемент в строке
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        }

        if (minVal != INT_MAX && minVal > 0) {
            // Вычитаем минимальный элемент из всех элементов строки
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] != INT_MAX) {
                    matrix[i][j] -= minVal;
                }
            }
            reductionCost += minVal;
        }
    }

    // Редукция столбцов
    for (int j = 0; j < matrix[0].size(); ++j) {
        int minVal = INT_MAX;
        // Находим минимальный элемент в столбце
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        }

        if (minVal != INT_MAX && minVal > 0) {
            // Вычитаем минимальный элемент из всех элементов столбца
            for (int i = 0; i < matrix.size(); ++i) {
                if (matrix[i][j] != INT_MAX) {
                    matrix[i][j] -= minVal;
                }
            }
            reductionCost += minVal;
        }
    }

    return matrix;
}

int TSP::calculateZeroCost(QVector<QVector<int>> matrix, int row, int col)
{
    int minRow = INT_MAX;
    int minCol = INT_MAX;

    for (int j = 0; j < matrix[row].size(); ++j) {
        if (j != col && matrix[row][j] < minRow) {
            minRow = matrix[row][j];
        }
    }

    for (int i = 0; i < matrix.size(); ++i) {
        if (i != row && matrix[i][col] < minCol) {
            minCol = matrix[i][col];
        }
    }

    return (minRow == INT_MAX ? 0 : minRow) + (minCol == INT_MAX ? 0 : minCol);
}


void TSP::on_removeVertexButton_clicked()
{
    if (vertices.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Нет вершин для удаления!");
        return;
    }

    // Создаем список вершин для выбора
    QStringList vertexList;
    for (int i = 0; i < vertices.size(); ++i) {
        vertexList << QString::number(i + 1);
    }

    bool ok;
    QString vertexToRemove = QInputDialog::getItem(this, "Удаление вершины",
                                                   "Выберите вершину для удаления:",
                                                   vertexList, 0, false, &ok);
    if (!ok) return;

    int vertexIndex = vertexToRemove.toInt() - 1;

    // Удаляем все связанные с вершиной элементы из сцены
    QGraphicsEllipseItem* vertexItem = vertices[vertexIndex];

    // Удаляем все ребра, связанные с этой вершиной
    QList<QGraphicsItem*> itemsToRemove;
    for (auto item : scene->items()) {
        if (auto line = dynamic_cast<QGraphicsLineItem*>(item)) {
            QLineF lineF = line->line();
            QPointF vertexCenter = vertexItem->pos() + QPointF(15, 15);

            // Проверяем, связано ли ребро с удаляемой вершиной
            if (lineF.p1() == vertexCenter || lineF.p2() == vertexCenter) {
                itemsToRemove.append(item);

                // Удаляем все текстовые метки стоимости этого ребра
                for (auto label : scene->items(lineF.center())) {
                    if (dynamic_cast<QGraphicsTextItem*>(label)) {
                        itemsToRemove.append(label);
                    }
                }
            }
        }
        // Удаляем текстовую метку вершины
        else if (auto text = dynamic_cast<QGraphicsTextItem*>(item)) {
            if (text->pos() == vertexItem->pos() + QPointF(15 - text->boundingRect().width()/2,
                                                           15 - text->boundingRect().height()/2)) {
                itemsToRemove.append(text);
            }
        }
    }

    // Удаляем все найденные элементы
    for (auto item : itemsToRemove) {
        scene->removeItem(item);
        delete item;
    }

    // Удаляем саму вершину
    scene->removeItem(vertexItem);
    delete vertexItem;

    // Удаляем вершину из вектора
    vertices.remove(vertexIndex);

    // Обновляем матрицу смежности
    adjacencyMatrix.remove(vertexIndex);
    for (auto &row : adjacencyMatrix) {
        row.remove(vertexIndex);
    }

    // Обновляем нумерацию оставшихся вершин
    for (int i = 0; i < vertices.size(); ++i) {
        for (auto item : scene->items(vertices[i]->pos())) {
            if (auto text = dynamic_cast<QGraphicsTextItem*>(item)) {
                text->setPlainText(QString::number(i + 1));
            }
        }
    }

    ui->resultLabel->setText(QString("Вершина %1 удалена").arg(vertexIndex + 1));
}

void TSP::on_removeEdgeButton_clicked()
{
    if (selectedEdgeItems.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Нет рёбер для удаления!");
        return;
    }

    // Создаем список рёбер для выбора
    QStringList edgeList;
    for (int i = 0; i < selectedEdgeItems.size(); ++i) {
        int from = selectedEdges[i].first + 1;
        int to = selectedEdges[i].second + 1;
        edgeList << QString("%1 ↔ %2").arg(from).arg(to);
    }

    bool ok;
    QString edgeToRemove = QInputDialog::getItem(this, "Удаление рёбер", "Выберите ребро для удаления:", edgeList, 0, false, &ok);
    if (!ok) return;

    // Получаем индексы вершин, между которыми находится выбранное ребро
    int edgeIndex = edgeList.indexOf(edgeToRemove);
    if (edgeIndex == -1) return;  // Если ничего не выбрано, выходим

    int fromIdx = selectedEdges[edgeIndex].first;
    int toIdx = selectedEdges[edgeIndex].second;

    // Удаляем ребро из сцены
    QGraphicsLineItem *edge = selectedEdgeItems[edgeIndex];
    scene->removeItem(edge);
    delete edge;

    // Удаляем текстовую метку стоимости
    QGraphicsTextItem *costLabel = selectedEdgeLabels[edgeIndex];
    scene->removeItem(costLabel);
    delete costLabel;

    // Удаляем рёбра из матрицы смежности
    adjacencyMatrix[fromIdx][toIdx] = INT_MAX;
    adjacencyMatrix[toIdx][fromIdx] = INT_MAX;

    // Удаляем ребро и текст из соответствующих списков
    selectedEdges.removeAt(edgeIndex);
    selectedEdgeItems.removeAt(edgeIndex);
    selectedEdgeLabels.removeAt(edgeIndex);

    ui->resultLabel->setText(QString("Ребро между %1 и %2 удалено").arg(fromIdx + 1).arg(toIdx + 1));
}

void TSP::on_clearButton_clicked()
{
    scene->clear();
    vertices.clear();
    adjacencyMatrix.clear();
    selectedEdges.clear();
    totalCost = 0;
    ui->resultLabel->setText("Граф очищен");
}

bool TSP::isOverlapping(int x, int y, int minDistance)
{
    for (auto vertex : vertices) {
        QPointF pos = vertex->pos();
        if (sqrt(pow(x - pos.x(), 2) + pow(y - pos.y(), 2) < minDistance)) {
            return true;
        }
    }
    return false;
}
