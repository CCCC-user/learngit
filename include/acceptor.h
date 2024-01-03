#ifndef _ACCETPOR_H_
#define _ACCETPOR_H_

#include <functional>

class EventLoop;
class Socket;
class InetAddress;
class Channel;

class Acceptor{
public:
    explicit Acceptor(EventLoop* loop);
    ~Acceptor();

    std::function<void(Socket*)> newconnectionCallback;
    void setNewConnectionCallback(std::function<void(Socket*)>);
    void accetpConnection();

private:
    EventLoop* m_loop;
    Socket* m_sock;
    InetAddress* m_addr;
    Channel* m_acceptchannel;
};

#endif