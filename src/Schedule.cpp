#include <thread>
#include <iostream>
#include "Schedule.h"


void Schedule::runEvents() {
    std::lock_guard<std::mutex> lock(mutex);
    auto now = std::chrono::system_clock::now();
    std::cout << "Running events" << std::endl;
    for (auto event = events.begin(); event != events.end();) {
        if (now >= event->first) {
            event->second();
            event = events.erase(event);
        } else {
            std::cout << "Event not ready" << std::endl;
            ++event;
        }
    }
}