# Basic-Echo-Server
Basic Echo Server made in C

# Docker
To build the image use: docker build -t echo_server .
To run the container use: docker run -p 3000:3000/udp echo_server

To send a request you can use: echo "Hello from client" | nc -u localhost 3000
