#include "CommandAndControl.hpp"
#include "HardwareSimulator.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>


int main() {
    HardwareSimulator hw;                          // Simulated hardware interface
    SystemState state = SystemState::IDLE;         // Initial system state
    std::string input;                             // Stores user input

    // Welcome screen and command list
    std::cout << "=============================\n";
    std::cout << " Welcome to the Embedded C2 Simulator\n";
    std::cout << "=============================\n";
    std::cout << "Available commands:\n";
    std::cout << "  - START             : Begin system operation\n";
    std::cout << "  - STOP              : Halt system operation\n";
    std::cout << "  - SET_SPEED <value> : Set motor speed (0–100)\n";
    std::cout << "  - STATUS            : Display system state and speed\n";
    std::cout << "  - CTRL+C            : Exit the program\n";
    std::cout << "=============================\n";

    // Main command loop
    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, input);
        Command cmd = parseUserInput(input);

        // Handle each command based on its type
        switch (cmd.type) {
            case CommandType::START:
                if (state == SystemState::IDLE) {
                    hw.start();
                    state = SystemState::RUNNING;
                } else {
                    std::cout << "[System] Already running or in error state.\n";
                }
                break;

            case CommandType::STOP:
                hw.stop();
                state = SystemState::IDLE;
                break;

            case CommandType::SET_SPEED:
                if (state == SystemState::RUNNING) {
                    hw.setSpeed(cmd.value);
                } else {
                    std::cout << "[System] Cannot set speed while not running.\n";
                }
                break;

            case CommandType::STATUS:
                std::cout << "[System] State: ";
                if (state == SystemState::IDLE) std::cout << "IDLE\n";
                else if (state == SystemState::RUNNING) std::cout << "RUNNING\n";
                else std::cout << "ERROR\n";
                hw.getStatus();
                break;

            case CommandType::INVALID:
            default:
                std::cout << "[System] Invalid command.\n";
                break;
        }
    }

    return 0;
}
