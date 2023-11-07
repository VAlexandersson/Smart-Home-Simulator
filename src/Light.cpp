
#include <iostream>
#include "../include/Light.h"


void Light::turnOn() {
    setState(true);
    std::cout << "Light is on: " << isOn() << std::endl;
}
void Light::turnOff() {
    setState(false);
    std::cout << "Light is on: " << isOn() << std::endl;
}
