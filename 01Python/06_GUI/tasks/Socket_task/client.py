import socket

# Server's IP address and port
server_address = ('localhost', 8888)

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
client_socket.connect(server_address)
print(f"Connected to {server_address}")

try:
    # Send data to the server
    message = "Hello, server!"
    client_socket.sendall(message.encode())

    # Receive data from the server
    data = client_socket.recv(1024)
    print(f"Received from server: {data.decode()}")

finally:
    # Close the socket connection
    print("Closing connection to the server.")
    client_socket.close()

