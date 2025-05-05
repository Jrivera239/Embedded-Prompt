#include "HardwareSimulator.hpp"
#include <iostream>

HardwareSimulator::HardwareSimulator() : speed(0) {}

void HardwareSimulator::start() {
    std::cout << "[Hardware] Motor started.\n";
}

void HardwareSimulator::stop() {
    std::cout << "[Hardware] Motor stopped.\n";
    speed = 0;
}

void HardwareSimulator::setSpeed(int s) {
    speed = s;
    std::cout << "[Hardware] Speed set to " << speed << ".\n";
}

void HardwareSimulator::getStatus() {
    std::cout << "[Hardware] Status: speed = " << speed << ".\n";
}
