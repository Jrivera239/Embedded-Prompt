#ifndef HARDWARE_SIMULATOR_HPP
#define HARDWARE_SIMULATOR_HPP

class HardwareSimulator {
private:
    int speed;
public:
    HardwareSimulator();
    void start();
    void stop();
    void setSpeed(int s);
    void getStatus();
};

#endif
