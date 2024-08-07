#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Define log levels
enum class LogLevel {
    Info,
    Warn,
    Error
};

// Logger class definition
class Logger {
public:
    // Method to log messages with a specific level
    static Logger& Log(LogLevel level) {
        static Logger instance;
        instance.currentLevel = level;
        return instance;
    }

    // Overloaded insertion operator to handle log messages
    template<typename T>
    Logger& operator<<(const T& message) {
        std::stringstream ss;
        ss << message;
        logBuffer.push_back(formatMessage(ss.str()));
        return *this;
    }

    // Method to dump all log messages
    static void Dump() {
        Logger& instance = Log(LogLevel::Info); // Use any level to access instance
        for (const auto& msg : instance.logBuffer) {
            std::cout << msg << std::endl;
        }
    }

    // Method to clear all log messages
    static void Clear() {
        Logger& instance = Log(LogLevel::Info); // Use any level to access instance
        instance.logBuffer.clear();
    }

private:
    // Format message with timestamp and log level
    std::string formatMessage(const std::string& message) {
        std::string levelStr;
        switch (currentLevel) {
            case LogLevel::Info: levelStr = "INFO"; break;
            case LogLevel::Warn: levelStr = "WARN"; break;
            case LogLevel::Error: levelStr = "ERROR"; break;
        }
        return "[" + levelStr + "] " + message;
    }

    LogLevel currentLevel;
    std::vector<std::string> logBuffer;

    // Private constructor to ensure singleton pattern
    Logger() {}
};

int main() {
    // Example usage of the Logger class
    Logger::Log(LogLevel::Info) << "This is an info message.";
    Logger::Log(LogLevel::Warn) << "This is a warning message.";
    Logger::Log(LogLevel::Error) << "This is an error message.";

    std::cout << "Log Dump:" << std::endl;
    Logger::Dump(); // Dump all logs

    Logger::Clear(); // Clear all logs

    std::cout << "Log Dump after Clear:" << std::endl;
    Logger::Dump(); // Should print nothing as the logs are cleared

    return 0;
}
