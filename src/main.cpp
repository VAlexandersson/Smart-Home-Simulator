#include <iostream>
#include "../include/Controller.h"
#include "../include/Light.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Controller<Light> lightController;

    auto livingRoomLight = std::make_shared<Light>();
    auto kitchenLight = std::make_shared<Light>();

    lightController.addDevice(livingRoomLight);
    lightController.addDevice(kitchenLight);

    lightController.turnAllOn();


    return 0;
}
