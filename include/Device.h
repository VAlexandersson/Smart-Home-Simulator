#ifndef SMART_HOME_SIMULATOR_DEVICE_H
#define SMART_HOME_SIMULATOR_DEVICE_H

class Device {
public:
    virtual ~Device() = default;

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    virtual bool getState() const = 0;
};

#endif //SMART_HOME_SIMULATOR_LIGHT_H
