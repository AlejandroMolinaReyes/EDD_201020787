/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *numeroEscritorio;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *numeroMantenimiento;
    QLabel *label_3;
    QLineEdit *numeroAvion;
    QLabel *label_4;
    QLineEdit *numeroTurno;
    QPlainTextEdit *consola;
    QPushButton *siguenteButton;
    QPushButton *reiniciarButton;
    QLabel *visorImg;
    QLabel *turnoLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(667, 475);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        numeroEscritorio = new QLineEdit(centralWidget);
        numeroEscritorio->setObjectName(QStringLiteral("numeroEscritorio"));
        numeroEscritorio->setGeometry(QRect(30, 30, 101, 20));
        numeroEscritorio->setReadOnly(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 111, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 10, 181, 16));
        numeroMantenimiento = new QLineEdit(centralWidget);
        numeroMantenimiento->setObjectName(QStringLiteral("numeroMantenimiento"));
        numeroMantenimiento->setGeometry(QRect(160, 30, 181, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(360, 10, 101, 16));
        numeroAvion = new QLineEdit(centralWidget);
        numeroAvion->setObjectName(QStringLiteral("numeroAvion"));
        numeroAvion->setGeometry(QRect(360, 30, 91, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(470, 10, 91, 16));
        numeroTurno = new QLineEdit(centralWidget);
        numeroTurno->setObjectName(QStringLiteral("numeroTurno"));
        numeroTurno->setGeometry(QRect(470, 30, 113, 20));
        consola = new QPlainTextEdit(centralWidget);
        consola->setObjectName(QStringLiteral("consola"));
        consola->setGeometry(QRect(30, 70, 321, 301));
        consola->setReadOnly(true);
        siguenteButton = new QPushButton(centralWidget);
        siguenteButton->setObjectName(QStringLiteral("siguenteButton"));
        siguenteButton->setGeometry(QRect(100, 380, 101, 31));
        reiniciarButton = new QPushButton(centralWidget);
        reiniciarButton->setObjectName(QStringLiteral("reiniciarButton"));
        reiniciarButton->setGeometry(QRect(480, 380, 91, 31));
        visorImg = new QLabel(centralWidget);
        visorImg->setObjectName(QStringLiteral("visorImg"));
        visorImg->setGeometry(QRect(370, 70, 271, 301));
        visorImg->setScaledContents(true);
        turnoLabel = new QLabel(centralWidget);
        turnoLabel->setObjectName(QStringLiteral("turnoLabel"));
        turnoLabel->setGeometry(QRect(290, 380, 91, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 667, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Numero de Escritorios", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Numero de Puestos de Mantenimiento", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Numero de Aviones", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Numero de Turnos", Q_NULLPTR));
        siguenteButton->setText(QApplication::translate("MainWindow", "Iniciar", Q_NULLPTR));
        reiniciarButton->setText(QApplication::translate("MainWindow", "Reiniciar", Q_NULLPTR));
        visorImg->setText(QString());
        turnoLabel->setText(QApplication::translate("MainWindow", "Turno: Iniciar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
