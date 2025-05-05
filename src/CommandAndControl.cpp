#include "CommandAndControl.hpp"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iostream>

// Used for suggestion matching
std::string toUpper(const std::string& str) {
    std::string upper = str;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    return upper;
}

// Suggests a valid command
std::string suggestSimilarCommand(const std::string& input) {
    std::string upperInput = toUpper(input);
    if (upperInput == "START") return "START";
    if (upperInput == "STOP") return "STOP";
    if (upperInput == "STATUS") return "STATUS";
    if (upperInput.rfind("SET_SPEED", 0) == 0) return "SET_SPEED <value>";
    return "";
}

// Prints a helpful message
CommandType parseCommand(const std::string& input) {
    if (input == "START") return CommandType::START;
    if (input == "STOP") return CommandType::STOP;
    if (input == "STATUS") return CommandType::STATUS;
    if (input.rfind("SET_SPEED ", 0) == 0) return CommandType::SET_SPEED;

    std::string suggestion = suggestSimilarCommand(input);
    if (!suggestion.empty()) {
        std::cout << "[System] Invalid command. Did you mean: " << suggestion << "?\n";
    } else {
        std::cout << "[System] Invalid command.\n";
    }

    return CommandType::INVALID;
}

// Parses user input into a Command with type 
Command parseUserInput(const std::string& input) {
    std::istringstream iss(input);
    std::string commandStr;
    iss >> commandStr;

    CommandType type = parseCommand(input);
    Command cmd{type};

    if (type == CommandType::SET_SPEED) {
        iss >> cmd.value;
    }

    return cmd;
}

