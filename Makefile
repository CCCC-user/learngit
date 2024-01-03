server:
	g++ ./src/util.cpp client.cpp -o client && \
	g++ ./src/util.cpp Server.cpp ./src/epoll.cpp ./src/inetaddress.cpp ./src/socket.cpp ./src/channel.cpp ./src/eventloop.cpp ./src/server.cpp ./src/acceptor.cpp -o server
clean:
	rm server && rm client