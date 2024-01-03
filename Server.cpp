#include "./include/eventloop.h"
#include "./include/server.h"

int main() {
    EventLoop *loop = new EventLoop();
    Server *server = new Server(loop);
    
    loop->loop();
    return 0;
}