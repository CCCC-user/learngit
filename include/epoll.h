#ifndef _EPOLL_H_
#define _EPOLL_H_

#include <sys/epoll.h>
#include <vector>

#include "./channel.h"

class Channel;
class Epoll{
public:
    Epoll();
    ~Epoll();

    void addFd(int fd, uint32_t op);
    //std::vector<epoll_event> poll(int timeout = -1);
    std::vector<Channel*> poll(int timeout = -1);

    void updateChannel(Channel*);
private:
    int m_epfd;
    struct epoll_event* m_events;
};
#endif