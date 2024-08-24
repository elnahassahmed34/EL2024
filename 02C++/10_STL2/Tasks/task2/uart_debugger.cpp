#include "uart_debugger.h"
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <cerrno>

UARTDebugger::UARTDebugger(const std::string& device, speed_t baudRate)
    : device_(device), baudRate_(baudRate), fd_(-1) {}

UARTDebugger::~UARTDebugger() {
    close();
}

bool UARTDebugger::open() {
    fd_ = ::open(device_.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
    if (fd_ < 0) {
        std::cerr << "Error opening UART: " << strerror(errno) << std::endl;
        return false;
    }
    configurePort();
    return true;
}

void UARTDebugger::close() {
    if (fd_ >= 0) {
        ::close(fd_);
        fd_ = -1;
    }
}

void UARTDebugger::configurePort() {
    struct termios tty;
    if (tcgetattr(fd_, &tty) != 0) {
        std::cerr << "Error getting UART attributes: " << strerror(errno) << std::endl;
        return;
    }

    cfsetospeed(&tty, baudRate_);
    cfsetispeed(&tty, baudRate_);
    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;
    tty.c_iflag &= ~IGNBRK;
    tty.c_lflag = 0;
    tty.c_oflag = 0;
    tty.c_cc[VMIN]  = 0;
    tty.c_cc[VTIME] = 5;

    if (tcsetattr(fd_, TCSANOW, &tty) != 0) {
        std::cerr << "Error setting UART attributes: " << strerror(errno) << std::endl;
    }
}

bool UARTDebugger::send(const std::string& message) {
    if (fd_ < 0) return false;
    return ::write(fd_, message.c_str(), message.size()) == static_cast<ssize_t>(message.size());
}

std::string UARTDebugger::receive() {
    if (fd_ < 0) return "";
    char buf[256];
    ssize_t n = ::read(fd_, buf, sizeof(buf) - 1);
    if (n > 0) {
        buf[n] = '\0';
        return std::string(buf);
    }
    return "";
}
