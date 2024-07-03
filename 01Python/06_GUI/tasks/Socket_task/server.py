import socket
import threading

# Function to handle each client connection
def handle_client(client_socket, client_address):
    print(f"Accepted connection from {client_address}")

    # Echo loop: receive data and send it back
    while True:
        data = client_socket.recv(1024)
        if not data:
            break
        client_socket.send(data)

    print(f"Connection from {client_address} closed.")
    client_socket.close()

# Main server function
def main():
    # Create a socket object
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Bind the socket to a specific IP address and port
    server_address = ('', 8888)  # Use '' to bind to all available interfaces
    server_socket.bind(server_address)

    # Listen for incoming connections (up to 5 clients)
    server_socket.listen(5)
    print("Server is listening for incoming connections...")

    # Main server loop: accept incoming connections and handle them
    while True:
        # Accept a new connection
        client_socket, client_address = server_socket.accept()

        # Create a new thread to handle the client
        client_thread = threading.Thread(target=handle_client, args=(client_socket, client_address))
        client_thread.start()

if __name__ == "__main__":
    main()
