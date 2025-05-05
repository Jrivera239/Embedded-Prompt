#ifndef COMMAND_AND_CONTROL_HPP
#define COMMAND_AND_CONTROL_HPP

#include <string>

// System states
enum class SystemState {
    IDLE,
    RUNNING,
    ERROR
};

// Command types
enum class CommandType {
    START,
    STOP,
    SET_SPEED,
    STATUS,
    INVALID
};

// Parsed command structure
struct Command {
    CommandType type;
    int value = 0;
};

// Interface
CommandType parseCommand(const std::string& input);
Command parseUserInput(const std::string& input);

#endif
