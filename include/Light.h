#ifndef SMART_HOME_SIMULATOR_LIGHT_H
#define SMART_HOME_SIMULATOR_LIGHT_H
#include "Device.h"

class Light : public Device {
public:
    void turnOn() override;
    void turnOff() override;
};

#endif //SMART_HOME_SIMULATOR_LIGHT_H
