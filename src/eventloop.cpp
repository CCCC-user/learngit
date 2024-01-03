#include "../include/eventloop.h"
#include "../include/epoll.h"

EventLoop::EventLoop() : m_loop(nullptr),
                        m_quit(false)
{
    m_loop = new Epoll();
}

EventLoop::~EventLoop()
{
    delete m_loop;
}

void EventLoop::loop()
{
    while(!m_quit){
        std::vector<Channel*> actiavteChs;
        actiavteChs = m_loop->poll();
        for(auto it = actiavteChs.begin(); it != actiavteChs.end(); it++){
            (*it)->handleEvent();
        }
    }
}

void EventLoop::updateChannel(Channel *ch)
{
    m_loop->updateChannel(ch);
}