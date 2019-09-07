# File-Transfer-Protocol:-
File Transfer Protocol (FTP) is a standard Internet protocol for transmitting files between computers on the Internet over TCP/IP connections. FTP is a client-server protocol where a client will ask for a file, and a local or remote server will provide it.This is implemented through Socket Programming.

# How to run it :-

# AT SERVER SIDE :-
make -f server.mk
./server PORTNUMBER FILENAME
 
# AT CLIENT SIDE :-
make -f client.mk
./client IP PORTNUMBER FILENAME
  
This will create object file. Command to cleam object file
  
At server side: make clean -f server.mk
  
At client side: make clean -f client.mk
