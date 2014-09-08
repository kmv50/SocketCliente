#include "clientesocket.h"

ClienteSocket::ClienteSocket()
{
}

bool ClienteSocket::Conectar()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor < 0)
    {
        cout << "Error al crear el socket" << endl;
        return false;
    }
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = inet_addr("127.0.0.1");
    info.sin_port = htons(4050);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));
    return true;
    if((::connect(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info))) < 0)
    {
        cout << "Error al conectar"<<endl;
        return false;
    }

    pthread_t hilo;
    pthread_create(&hilo,0,ClienteSocket::getMensaje,(void *)this);
    pthread_detach(hilo);
    return true;
}

void * ClienteSocket::getMensaje(void *obj)
{
    ClienteSocket *padre = (ClienteSocket *)obj;
    int pDescriptor = padre->descriptor;
    while (true) {
        string mensaje;
        while (1) {
            char buffer[10] = {0};
            int bytes = recv(pDescriptor,buffer,10,0);
            mensaje.append(buffer,bytes);
            if(bytes < 10)
                break;
        }
        emit padre->NuevoMensaje(QString::fromStdString(mensaje));
    }

    close(pDescriptor);
    pthread_exit(NULL);
}


void ClienteSocket::setMensaje(QString msn)
{
    cout <<"Enviados" << send(descriptor,msn.toStdString().c_str(),msn.length(),0) << endl;
}
