#include "../include/acceptor.h"
#include "../include/socket.h"
#include "../include/inetaddress.h"
#include "../include/channel.h"

Acceptor::Acceptor(EventLoop* loop) : m_loop(loop) {
    Socket *serv_sock = new Socket();
    InetAddress *serv_addr = new InetAddress("127.0.0.1", 8888);
    serv_sock->bind(serv_addr);
    serv_sock->listen();
    serv_sock->setNoBlocking();

    m_acceptchannel = new Channel(m_loop, serv_sock->getFd());
    std::function<void()> cb = std::bind(&Acceptor::accetpConnection, this);

    m_acceptchannel->setCallBack(cb);
    m_acceptchannel->enableReading();
}

Acceptor::~Acceptor() {
    delete m_sock;
    delete m_addr;
    delete m_acceptchannel;
}

void Acceptor::setNewConnectionCallback(std::function<void(Socket*)> _cb) {
    newconnectionCallback = _cb;
}


void Acceptor::accetpConnection() {
    newconnectionCallback(m_sock);
}