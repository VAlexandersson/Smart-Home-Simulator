#ifndef SMART_HOME_SIMULATOR_CONTROLLER_H
#define SMART_HOME_SIMULATOR_CONTROLLER_H

#include <vector>
#include <memory>

template <typename T>
class Controller {
private:
    std::vector<std::shared_ptr<T>> devices;

public:
    void addDevice(std::shared_ptr<T> device);
    void turnAllOn();
    void turnAllOff();
};

// Implementations.

template <typename T>
void Controller<T>::addDevice(std::shared_ptr<T> device) {
    devices.push_back(device);
}

template <typename T>
void Controller<T>::turnAllOn() {
    for(auto& device : devices)
        device->turnOn();
}

template <typename T>
void Controller<T>::turnAllOff() {
    for(auto& device : devices)
        device->turnOff();
}

// Note to future self: Put inside Controller.tpp instead... Decisions.

#endif //SMART_HOME_SIMULATOR_CONTROLLER_H