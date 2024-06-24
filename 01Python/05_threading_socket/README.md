

# Python Threading Guide

This guide provides a brief introduction to threading in Python, including how to create and manage threads for concurrent execution.

## What is Threading?

Threading is a technique that allows a program to run multiple operations concurrently in the same process space. Each operation runs in its own thread. This is useful for I/O-bound tasks like reading from a file or network operations.

## Basic Usage

To use threading in Python, you need to import the `threading` module. Below is a simple example:

```python
import threading
import time

def print_numbers():
    for i in range(5):
        time.sleep(1)
        print(f'Number: {i}')

def print_letters():
    for letter in 'abcde':
        time.sleep(1)
        print(f'Letter: {letter}')

# Create threads
thread1 = threading.Thread(target=print_numbers)
thread2 = threading.Thread(target=print_letters)

# Start threads
thread1.start()
thread2.start()

# Wait for both threads to complete
thread1.join()
thread2.join()

print("Both threads have finished execution.")
```

- In this example:

Two functions, print_numbers and print_letters, are defined to simulate tasks.
Two threads are created, each targeting one of these functions.
The start() method begins execution of the threads.
The join() method ensures the main program waits for the threads to complete before proceeding.

## Thread Synchronization
To avoid conflicts and ensure correct execution order, use synchronization primitives like Lock.

```python
lock = threading.Lock()

def synchronized_print_numbers():
    with lock:
        for i in range(5):
            time.sleep(1)
            print(f'Number: {i}')

def synchronized_print_letters():
    with lock:
        for letter in 'abcde':
            time.sleep(1)
            print(f'Letter: {letter}')

# Create threads
thread1 = threading.Thread(target=synchronized_print_numbers)
thread2 = threading.Thread(target=synchronized_print_letters)

# Start threads
thread1.start()
thread2.start()

# Wait for both threads to complete
thread1.join()
thread2.join()

print("Both synchronized threads have finished execution.")
```

- In this synchronized example:

A Lock object is created.
The with lock: statement ensures that only one thread can execute the code block at a time, preventing race conditions.

## Conclusion
Threading is a powerful tool for managing concurrent operations in Python. By using the threading module, you can create, start, and synchronize threads easily.



# Python Socket Programming Guide

This guide provides a brief introduction to socket programming in Python, including how to create and manage sockets for network communication.

## What is Socket Programming?

Socket programming is a way to enable communication between devices over a network. It involves creating sockets that can send and receive data between a client and a server.

## Basic Usage

To use sockets in Python, you need to import the `socket` module. Below is a simple example of a basic client-server communication.

### Server Code

```python
import socket

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 12345))
    server_socket.listen(5)
    print("Server is listening on port 12345")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Connection from {addr} has been established.")
        client_socket.send(bytes("Welcome to the server!", "utf-8"))
        client_socket.close()

if __name__ == "__main__":
    start_server()
```

### Client Code
```python
import socket

def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 12345))

    msg = client_socket.recv(1024)
    print(msg.decode("utf-8"))

    client_socket.close()

if __name__ == "__main__":
    start_client()
```

## In these examples:

- The server code creates a socket, binds it to a local address and port, and listens for incoming connections.
- When a connection is accepted, it sends a welcome message to the client and then closes the connection.
- The client code creates a socket, connects to the server, receives the welcome message, and then closes the connection.




