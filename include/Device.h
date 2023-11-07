#ifndef SMART_HOME_SIMULATOR_DEVICE_H
#define SMART_HOME_SIMULATOR_DEVICE_H

class Device {
private:
    bool state;
public:
    Device() : state(false) {}
    virtual ~Device() = default;

    void setState(bool state) { this->state = state; }

    bool isOn() const { return state; }

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

#endif //SMART_HOME_SIMULATOR_LIGHT_H
