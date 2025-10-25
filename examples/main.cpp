#include "profiler/ProfileScope.hpp"
#include "profiler/AutoProfileScope.hpp"
#include "profiler/ProfilerRegistry.hpp"
#include <thread>

using namespace profiler;

void simulateWork() {
    AutoProfileScope<> autoScope;
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
}

int main() {
    for (int i = 0; i < 3; ++i) {
        {
            ProfileScope<"Function"> scope;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        simulateWork();
    }

    ProfilerRegistry::instance().report();
}