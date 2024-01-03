#ifndef _SERVER_H_
#define _SERVER_H_

class EventLoop;
class Socket;
class Acceptor;

class Server{
public:
    Server(EventLoop *);
    ~Server();

    void handleReadEvent(int sockfd);
    void newConnection(Socket *serv_sock);
private:
    EventLoop *m_loop;
    Acceptor *m_acceptor;
};

#endif