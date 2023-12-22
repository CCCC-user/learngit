#ifndef _CHANNEL_H
#define _CHANNEL_H

#include "./epoll.h"

class Epoll;
class Channel{
public:
    Channel(Epoll* ep, int fd);
    ~Channel();

    uint32_t getEvents();
    uint32_t getRevents();
    bool getInEpoll();
    void setInEpoll();
    void setRevents(uint32_t);
    int getFd();
    void enableReading();

private:
    int m_fd;
    Epoll* m_ep;

    uint32_t m_events;
    uint32_t m_revents;
    bool m_inEpoll;
};

#endif