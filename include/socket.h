#ifndef _SOCKET_H_
#define _SOCKET_H_

class InetAddress;
class Socket{
public:
    Socket();
    Socket(int);
    ~Socket();

    void bind(InetAddress*);
    void listen();
    int accept(InetAddress*);

    void setNoBlocking();

    int getFd();

private:
    int m_fd;
};

#endif 