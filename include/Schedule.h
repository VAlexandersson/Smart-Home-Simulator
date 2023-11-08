#ifndef SMART_HOME_SIMULATOR_SCHEDULE_H
#define SMART_HOME_SIMULATOR_SCHEDULE_H


#include <vector>
#include <chrono>
#include <functional>
#include <mutex>

class Schedule {
private:
    std::vector<std::pair<std::chrono::system_clock::time_point, std::function<void()>>> events;
    std::mutex mutex;

public:
    void addEvent(std::chrono::system_clock::time_point time, const std::function<void()>& event) {
        std::lock_guard<std::mutex> lock(mutex);
        events.emplace_back(time, event);
    }
    void runEvents();
};


#endif //SMART_HOME_SIMULATOR_SCHEDULE_H