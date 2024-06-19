# Echo Server
Echo Server made in C

## Build and Run Docker
To build the image use: `docker build -t echo_server .` <br>
To run the container use: `docker run -p 3000:3000/udp echo_server` <br>
To compile the project: `gcc -Iext/include/ -o server src/*.c ext/src/*.c` <br>

## Send a Request
### Linux
```bash
echo "Hello from client" | nc -u localhost 3000 
```

### Windows
```bat
echo "Hello from client" | C:\Path\To\ncat.exe -u localhost 3000
```
