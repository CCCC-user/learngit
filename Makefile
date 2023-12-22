server:
	g++ ./src/util.cpp client.cpp -o client && \
	g++ ./src/util.cpp server.cpp ./src/epoll.cpp ./src/inetaddress.cpp ./src/socket.cpp ./src/channel.cpp -o server
clean:
	rm server && rm client