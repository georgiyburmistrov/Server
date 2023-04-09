/**
 * Сервер прослушивает ПОРТ: 2323
 */
#include "server.h"

server::server()
{
    if(this -> listen(QHostAddress:: Any, 2323)){

        qDebug() << "start";

    }
    else{

        qDebug() << "error";

    }


}

void server:: incomingConnection(qintptr socketDescriptor){

    socket = new QTcpSocket;
    socket -> setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket); // ВНИМАНИЕ!!!! ЗДЕСЬ В ВИДЕО НЕТ ОШИБКИ!!!
    qDebug() << "client connected" << socketDescriptor;
}

void server:: slotReadyRead(){

}
