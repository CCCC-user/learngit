#include "../include/channel.h"

Channel::Channel(EventLoop* ep, int fd) : m_ep(ep), m_fd(fd), m_events(0), m_revents(0), m_inEpoll(false) {
    
}

Channel::~Channel() {

}

uint32_t Channel::getEvents() {
    return m_events;
}

uint32_t Channel::getRevents() {
    return m_revents;
}

bool Channel::getInEpoll() {
    return m_inEpoll;
}

void Channel::setInEpoll() {
    m_inEpoll = true;
}

void Channel::setRevents(uint32_t ev) {
    m_revents = ev;
}

int Channel::getFd() {
    return m_fd;
}

void Channel::enableReading() {
    m_events = EPOLLIN | EPOLLET;
    m_ep->updateChannel(this);
}

void Channel::handleEvent() {
    m_callback();
}

void Channel::setCallBack(std::function<void()> cb) {
    m_callback = cb;
}