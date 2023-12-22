#include "../include/socket.h"
#include "../include/inetaddress.h"
#include "../include/util.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>

void Socket::setNoBlocking() {
    fcntl(m_fd, F_SETFL, fcntl(m_fd, F_GETFL) | O_NONBLOCK);
}

Socket::Socket() : m_fd(-1) {
    m_fd = socket(AF_INET, SOCK_STREAM, 0);
    errif(m_fd==-1, " socket create error!");
}

Socket::Socket(int fd) : m_fd(fd) {
    errif(fd == -1, "socket create error!");
}

Socket::~Socket() {
    if(m_fd != -1){
        close(m_fd);
        m_fd = -1;
    }
}

void Socket::bind(InetAddress *addr) {
    errif(::bind(m_fd, (sockaddr*)&addr->m_addr, addr->m_addr_len) == -1, "socket bind error");
}

void Socket::listen() {
    errif(::listen(m_fd, SOMAXCONN) == -1, "socket listen error!");
}

int Socket::accept(InetAddress *addr){
    int clnt_sockfd = ::accept(m_fd, (sockaddr*)&addr->m_addr, &addr->m_addr_len);
    errif(clnt_sockfd == -1, "socket accetp error");
    return clnt_sockfd;
}

int Socket::getFd() {
    return m_fd;
}