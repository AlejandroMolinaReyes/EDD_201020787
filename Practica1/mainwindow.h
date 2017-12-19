#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QMessageBox>
#include <graficar.h>
#include <coladoble.h>
#include <avion.h>
#include <colasimple.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_siguenteButton_clicked();

    void on_reiniciarButton_clicked();

private:
    bool validarInicio;
    int turnoActual;
    colaDoble *colaAviones;
    colaSimple *colaPasajeros;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
