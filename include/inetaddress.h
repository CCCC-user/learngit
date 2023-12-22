#ifndef _INETADDRESS_H
#define _INETADDRESS_H

#include <arpa/inet.h>

class InetAddress{
public:
    struct sockaddr_in m_addr;
    socklen_t m_addr_len;
    
public:
    InetAddress();
    InetAddress(const char* ip, uint16_t port);
    ~InetAddress();
};


#endif 