#!/bin/bash

# Start Docker container in detached mode
docker run -d -p 3000:3000/udp --name echo-server echo_server

# Give some time for the server to start
sleep 2

# Perform health check
RESPONSE=$(echo "Hello from client" | timeout 1 nc -u 127.0.0.1 3000 | head -n1)
if [ "$RESPONSE" != "Hello from client" ]; then
  echo "Healthcheck failed: unexpected response '$RESPONSE'"
  docker logs echo-server
  exit 1
fi

# Stop and remove the Docker container
docker stop echo-server
docker rm echo-server
