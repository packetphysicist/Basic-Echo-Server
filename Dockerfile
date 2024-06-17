FROM gcc:latest

WORKDIR /usr/src/app
COPY . .

RUN apt-get update && \
   apt-get install build-essential -y

RUN gcc server.c -o server

ENTRYPOINT [ "./server" ]

LABEL maintainer="PacketPhysicist"
LABEL description="Docker image for a simple echo server in C"

