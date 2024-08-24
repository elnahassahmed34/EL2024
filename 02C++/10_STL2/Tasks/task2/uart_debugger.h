#ifndef UART_DEBUGGER_H
#define UART_DEBUGGER_H

#include <termios.h>
#include <string>

class UARTDebugger {
public:
    UARTDebugger(const std::string& device, speed_t baudRate);
    ~UARTDebugger();

    bool open();
    void close();
    bool send(const std::string& message);
    std::string receive();

private:
    std::string device_;
    speed_t baudRate_;
    int fd_; // File descriptor for the UART port

    void configurePort();
};

#endif // UART_DEBUGGER_H
