#include "uart_debugger.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    UARTDebugger uart("/dev/ttyS0", B9600); // Adjust device and baud rate as necessary

    if (!uart.open()) {
        std::cerr << "Failed to open UART port" << std::endl;
        return 1;
    }

    std::string message = "Hello UART";
    if (!uart.send(message)) {
        std::cerr << "Failed to send message" << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait for the receiver to process

    std::string response = uart.receive();
    if (!response.empty()) {
        std::cout << "Received: " << response << std::endl;
    } else {
        std::cout << "No data received" << std::endl;
    }

    uart.close();
    return 0;
}
