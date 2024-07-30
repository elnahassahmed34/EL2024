#include <iostream>
#include <csignal>

void signalHandler(int signal) {
    std::cout << "Interrupt signal (" << signal << ") received.\n";
    // Cleanup and close resources here
    exit(signal);
}

int main() {
    // Register signal and signal handler
    signal(SIGINT, signalHandler);

    std::cout << "Program running. Press Ctrl+C to interrupt.\n";
    while (true) {
        // Infinite loop, simulating a running program
    }

    return 0;
}
