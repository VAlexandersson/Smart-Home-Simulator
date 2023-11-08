#include <iostream>
#include <thread>
#include "Controller.h"
#include "Light.h"
#include "Schedule.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Schedule scheduler;
    Controller<Light> lightController;

    auto livingRoomLight = std::make_shared<Light>();
    auto kitchenLight = std::make_shared<Light>();
    lightController.addDevice(livingRoomLight);
    lightController.addDevice(kitchenLight);


    scheduler.addEvent(std::chrono::system_clock::now() + std::chrono::seconds(5), [&lightController] {
        lightController.turnAllOn();
        std::cout << "Living room light turned on." << std::endl;
    });

    scheduler.addEvent(std::chrono::system_clock::now() + std::chrono::seconds(5), [&lightController] {
        lightController.turnAllOff();
        std::cout << "Living room light turned off." << std::endl;
    });


    std::thread eventThread([&scheduler](){
        while(true) {
            scheduler.runEvents();
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "main thread 1 second" << std::endl;
        }
    });
    eventThread.join();



    std::cout << "End of program." << std::endl;
    return 0;

}
