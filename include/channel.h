#ifndef _CHANNEL_H
#define _CHANNEL_H

#include "./epoll.h"
#include "./eventloop.h"

#include <functional>

class Epoll;
class EventLoop;

class Channel{
public:
    Channel(EventLoop* ep, int fd);
    ~Channel();

    uint32_t getEvents();
    uint32_t getRevents();
    bool getInEpoll();
    void setInEpoll();
    void setRevents(uint32_t);
    int getFd();

    void enableReading();
    void handleEvent();
    void setCallBack(std::function<void()>);

private:
    int m_fd;
    EventLoop* m_ep;

    uint32_t m_events;
    uint32_t m_revents;
    bool m_inEpoll;

    std::function<void()> m_callback;
};

#endif