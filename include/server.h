#ifndef _SERVER_H_
#define _SERVER_H_

class EventLoop;
class Socket;

class Server{
public:
    Server(EventLoop *);
    ~Server();

    void handleReadEvent(int sockfd);
    void newConnection(Socket *serv_sock);
private:
    EventLoop *m_loop;
};

#endif