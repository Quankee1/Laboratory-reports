/********************************************************************************
** Form generated from reading UI file 'tsp.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TSP_H
#define UI_TSP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TSP
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *addVertexButton;
    QPushButton *addEdgeButton;
    QPushButton *solveButton;
    QPushButton *clearButton;
    QLabel *resultLabel;
    QPushButton *removeVertexButton;
    QPushButton *removeEdgeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TSP)
    {
        if (TSP->objectName().isEmpty())
            TSP->setObjectName("TSP");
        TSP->resize(800, 600);
        centralwidget = new QWidget(TSP);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(330, 30, 431, 411));
        addVertexButton = new QPushButton(centralwidget);
        addVertexButton->setObjectName("addVertexButton");
        addVertexButton->setGeometry(QRect(50, 20, 211, 61));
        addEdgeButton = new QPushButton(centralwidget);
        addEdgeButton->setObjectName("addEdgeButton");
        addEdgeButton->setGeometry(QRect(50, 100, 211, 51));
        solveButton = new QPushButton(centralwidget);
        solveButton->setObjectName("solveButton");
        solveButton->setGeometry(QRect(50, 170, 211, 51));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(50, 380, 211, 51));
        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setGeometry(QRect(10, 460, 321, 91));
        QFont font;
        font.setPointSize(14);
        resultLabel->setFont(font);
        resultLabel->setWordWrap(true);
        removeVertexButton = new QPushButton(centralwidget);
        removeVertexButton->setObjectName("removeVertexButton");
        removeVertexButton->setGeometry(QRect(50, 240, 211, 51));
        removeEdgeButton = new QPushButton(centralwidget);
        removeEdgeButton->setObjectName("removeEdgeButton");
        removeEdgeButton->setGeometry(QRect(50, 310, 211, 51));
        TSP->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TSP);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        TSP->setMenuBar(menubar);
        statusbar = new QStatusBar(TSP);
        statusbar->setObjectName("statusbar");
        TSP->setStatusBar(statusbar);

        retranslateUi(TSP);

        QMetaObject::connectSlotsByName(TSP);
    } // setupUi

    void retranslateUi(QMainWindow *TSP)
    {
        TSP->setWindowTitle(QCoreApplication::translate("TSP", "TSP", nullptr));
        addVertexButton->setText(QCoreApplication::translate("TSP", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262\320\265\321\200\321\210\320\270\320\275\321\203", nullptr));
        addEdgeButton->setText(QCoreApplication::translate("TSP", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\265\320\261\321\200\320\276", nullptr));
        solveButton->setText(QCoreApplication::translate("TSP", "\320\240\320\265\321\210\320\270\321\202\321\214 TSP", nullptr));
        clearButton->setText(QCoreApplication::translate("TSP", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\263\321\200\320\260\321\204", nullptr));
        resultLabel->setText(QString());
        removeVertexButton->setText(QCoreApplication::translate("TSP", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\320\265\321\200\321\210\320\270\320\275\321\203", nullptr));
        removeEdgeButton->setText(QCoreApplication::translate("TSP", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\200\320\265\320\261\321\200\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TSP: public Ui_TSP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TSP_H
