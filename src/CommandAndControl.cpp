#include "CommandAndControl.hpp"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iostream>

// Helper: convert input string to uppercase for comparison
std::string toUpper(const std::string& str) {
    std::string upper = str;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    return upper;
}

// Suggest command if input was close but incorrect
std::string suggestSimilarCommand(const std::string& input) {
    std::string upperInput = toUpper(input);
    if (upperInput == "START") return "START";
    if (upperInput == "STOP") return "STOP";
    if (upperInput == "STATUS") return "STATUS";
    if (upperInput.rfind("SET_SPEED", 0) == 0) return "SET_SPEED <value>";
    return "";
}

// Parses the raw input to determine command type
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

// Parses full user input into Command struct
Command parseUserInput(const std::string& input) {
    std::istringstream iss(input);
    std::string commandStr;
    iss >> commandStr;
    CommandType type = parseCommand(input);  // pass entire string for SET_SPEED match
    Command cmd{type};

    if (type == CommandType::SET_SPEED) {
        iss >> cmd.value;
    }
    return cmd;
}
