#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    conexion = new SocketCliente;
    if(!conexion->connectar())
        QMessageBox::critical(this,"Error","Error al conectar con el servidor",QMessageBox::Ok);

    connect(conexion,SIGNAL(NewMensaje(QString)),SLOT(printMensaje(QString)));
    connect(ui->b_enviar,SIGNAL(clicked()),SLOT(sendMensaje()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::sendMensaje()
{
    conexion->setMensaje(ui->txt_mensaje->text().toStdString().c_str());

}

void MainWindow::printMensaje(QString msn)
{
    ui->txt_log->setPlainText(msn);
}
