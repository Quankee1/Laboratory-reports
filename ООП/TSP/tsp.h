#ifndef TSP_H
#define TSP_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QVector>
#include <QPair>
#include <QMouseEvent>
#include <climits>

QT_BEGIN_NAMESPACE
namespace Ui { class TSP; }
QT_END_NAMESPACE

class TSP : public QMainWindow
{
    Q_OBJECT

public:
    explicit TSP(QWidget *parent = nullptr);
    ~TSP();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    // Основные кнопки
    void on_addVertexButton_clicked();
    void on_addEdgeButton_clicked();
    void on_solveButton_clicked();
    void on_clearButton_clicked();
    void on_removeVertexButton_clicked();
    void on_removeEdgeButton_clicked();

private:
    Ui::TSP *ui;
    QGraphicsScene *scene;
    QVector<QGraphicsEllipseItem*> vertices;
    QVector<QVector<int>> adjacencyMatrix;
    QVector<QPair<int, int>> selectedEdges;
     QVector<QGraphicsLineItem*> selectedEdgeItems;
    QVector<QGraphicsTextItem*> selectedEdgeLabels;
    int totalCost;


    // Основные методы алгоритма
    QVector<QVector<int>> reduceMatrix(QVector<QVector<int>> matrix, int &reductionCost);
    int calculateZeroCost(QVector<QVector<int>> matrix, int row, int col);

    // Вспомогательные методы
    void addVertexAtPosition(const QPointF &pos);
    bool isOverlapping(int x, int y, int minDistance);

};

#endif // TSP_H
