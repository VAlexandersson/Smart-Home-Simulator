#ifndef SMART_HOME_SIMULATOR_DEVICE_H
#define SMART_HOME_SIMULATOR_DEVICE_H

class Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Device() { }
};

#endif //SMART_HOME_SIMULATOR_DEVICE_H
