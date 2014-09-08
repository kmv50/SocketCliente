#ifndef CLIENTESOCKET_H
#define CLIENTESOCKET_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>
#include <arpa/inet.h>
#include <QObject>
#include <QString>

using namespace std;

class ClienteSocket:public QObject
{
    Q_OBJECT
public:
    ClienteSocket();
    bool Conectar();
    void setMensaje(QString msn);
private:
    int descriptor;
    sockaddr_in info;
    static void * getMensaje(void *obj);
signals:
    void NuevoMensaje(QString msn);

};

#endif // CLIENTESOCKET_H
