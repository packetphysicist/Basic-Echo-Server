#!/bin/bash

# Wait for server to start
sleep 5

# Define test message
MESSAGE="Hello from the Client!"

# Send packet to the server
echo -n $MESSAGE | nc -u localhost 3000 > received_message.txt

# Check if response matches the sent packet
if grep -q "$MESSAGE" received_message.txt; then
    echo "UDP echo server test passed"
    exit 0
else
    echo "UDP echo server test failed"
    exit 1
fi
