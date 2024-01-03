#ifndef _EVENTLOOP_H_
#define _EVENTLOOP_H_

class Epoll;
class Channel;

class EventLoop{
public:
    explicit EventLoop();
    ~EventLoop();

    void loop();
    void updateChannel(Channel *ch);

private:
    Epoll *m_loop;
    bool m_quit;
};


#endif