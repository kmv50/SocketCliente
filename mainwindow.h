#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <socketcliente.h>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SocketCliente *conexion;
private slots:
    void printMensaje(QString msn);
    void sendMensaje();
};

#endif // MAINWINDOW_H
