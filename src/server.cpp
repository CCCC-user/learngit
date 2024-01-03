#include "../include/server.h"
#include "../include/eventloop.h"
#include "../include/socket.h"
#include "../include/inetaddress.h"
#include "../include/channel.h"
#include "../include/acceptor.h"
#include <functional>
#include <string.h>
#include <unistd.h>

Server::Server(EventLoop* loop) : m_loop(loop) {
    m_acceptor = new Acceptor(loop);
    std::function<void(Socket*)> cb = std::bind(&Server::newConnection, this, std::placeholders::_1);
    m_acceptor->setNewConnectionCallback(cb);
}

Server::~Server() {

}

void Server::handleReadEvent(int sockfd) {
    char buf[1024];
    while(true) {
        bzero(buf, sizeof(buf));
        ssize_t bytes_read = read(sockfd, buf, sizeof(buf));

        if(bytes_read > 0){
            printf("message from client fd %d: %s\n", sockfd, buf);
            write(sockfd, buf, sizeof(buf));
        } else if(bytes_read == -1 && errno == EINTR){
            printf("continue read");
            continue;
        } else if(bytes_read == -1 && ((errno == EAGAIN) || (errno == EWOULDBLOCK))){
            printf("finish read once, errno : %d \n", errno);
            break;
        } else if(bytes_read == 0){
            printf("EOF, client fd %d disconnected\n", sockfd);
            close(sockfd);   //关闭socket会自动将文件描述符从epoll树上移除
            break;
        }
    }
}

void Server::newConnection(Socket *serv_sock) {
    InetAddress* clnt_addr = new InetAddress();
    Socket* clnt_sock = new Socket(serv_sock->accept(clnt_addr));
    clnt_sock->setNoBlocking();

    Channel* clnt_channel = new Channel(m_loop, clnt_sock->getFd());
    std::function<void()> cb= std::bind(&Server::handleReadEvent, this , clnt_sock->getFd());
    clnt_channel->setCallBack(cb);
    clnt_channel->enableReading();
}