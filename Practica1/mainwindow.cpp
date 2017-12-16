#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->numeroEscritorio->setValidator(new QIntValidator(this));
    ui->numeroMantenimiento->setValidator(new QIntValidator(this));
    ui->numeroAvion->setValidator(new QIntValidator(this));
    ui->numeroTurno->setValidator(new QIntValidator(this));
    validarInicio = true;
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_siguenteButton_clicked()
{
    if(ui->numeroEscritorio->text()!= "" && ui->numeroMantenimiento->text() != "" && ui->numeroAvion->text()!="" &&  ui->numeroTurno->text()!="" && validarInicio==true)
    {
        // *********** valores iniciales de la interfaz grafica
        ui->numeroEscritorio->setReadOnly(true);
        ui->numeroMantenimiento->setReadOnly(true);
        ui->numeroAvion->setReadOnly(true);
        ui->numeroTurno->setReadOnly(true);
        ui->consola->appendPlainText(
                    "***** Iniciar simulacion *****\nNumero de escritorios: " + ui->numeroEscritorio->text()
                    + "\nNumero de puesto de mantenimiento: " + ui->numeroMantenimiento->text()
                    + "\nNumero de aviones: " + ui->numeroAvion->text()
                    + "\nNumero de turnos: " + ui->numeroTurno->text()
                    + "\n-------------------------------------------"
                    );
        ui->siguenteButton->setText("Siguente turno");
        ui->turnoLabel->setText("Turno: " + QString::number(turnoActual));
        turnoActual = 0;
        //****************************************************************
        //******** iniciando estructura
        //------------------ aviones
        int numeroAviones = ui->numeroAvion->text().toInt();
        int contadorAviones = 1;
        colaAviones = (colaDoble*)malloc(sizeof(colaDoble));
        inicializarColaDoble(colaAviones);
        while(contadorAviones<=numeroAviones){
            Avion *avion = (Avion*)malloc(sizeof(Avion));
            int desabordaje = 1 + rand()%(1+1-3);
            if(desabordaje==1){
                 avion->desabordaje = desabordaje;
                 avion->pajeros = 5 + rand()%(5+1-10);
                 avion->mantenimiento = 1 + rand()%(1+1-3);
            }else if(desabordaje==2){
                avion->desabordaje = desabordaje;
                avion->pajeros = 15 + rand()%(15+1-25);
                avion->mantenimiento = 2 + rand()%(2+1-4);
            }else if(desabordaje==3){
                avion->desabordaje = desabordaje;
                avion->pajeros =  + 30 + rand()%(30+1-40);
                avion->mantenimiento = 3 + rand()%(3+1-6);
            }
            pushDoble(colaAviones,contadorAviones,avion);
            contadorAviones++;
        }
        //------------------ Pasajeros

        //------------------ Escritorios
        int numeroEscrtorios = ui->numeroEscritorio->text().toInt();
        int contadorEscritorios = 1;
        //mostrarListaPrimeroCola(colaAviones);
        //********************************************************
        // ************************** ingresar la imagen diagrama
        QPixmap img1(QDir::currentPath()+"/diagrama.jpg");
        ui->visorImg->setPixmap(img1);
        //********************************
        validarInicio=false;
        Graficar graficar(colaAviones);
    }
    if(validarInicio==false)
    {

        Graficar graficar(colaAviones);
        QPixmap img1(QDir::currentPath()+"/diagrama.jpg");
        ui->visorImg->setPixmap(img1);
        ui->turnoLabel->setText("Turno: " + QString::number(turnoActual++));
    }

}

void MainWindow::on_reiniciarButton_clicked()
{
    ui->numeroEscritorio->setReadOnly(false);
    ui->numeroMantenimiento->setReadOnly(false);
    ui->numeroAvion->setReadOnly(false);
    ui->numeroTurno->setReadOnly(false);
    ui->numeroEscritorio->setText("");
    ui->numeroMantenimiento->setText("");
    ui->numeroAvion->setText("");
    ui->numeroTurno->setText("");
    ui->consola->clear();
    ui->siguenteButton->setText("Iniciar");
    ui->visorImg->clear();
    ui->turnoLabel->setText("Turno: Iniciar");
    validarInicio=true;
}
