#ifndef SMART_HOME_SIMULATOR_LIGHT_H
#define SMART_HOME_SIMULATOR_LIGHT_H
#include "Device.h"

class Light : public Device {
private:
    bool state = false;
public:
    Light() : state(false) { }

    void turnOn() override {
        state = true;
    }

    void turnOff() override {
        state = false;
    }
    bool getState() const override { return state; }
};

#endif //SMART_HOME_SIMULATOR_LIGHT_H
