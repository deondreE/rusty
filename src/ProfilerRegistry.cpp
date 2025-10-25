#include "profiler/ProfilerRegistry.hpp"
#include <iomanip>

namespace profiler {
    
ProfilerRegistry& ProfilerRegistry::instance() {
    static ProfilerRegistry reg;
    return reg; 
}

void ProfilerRegistry::record(std::string_view name, double ms) 
{
    std::scoped_lock lock(_mtx);
    auto&[totalTime, callCount] = _data[std::string(name)];
    callCount++;
    totalTime += ms;
}

void ProfilerRegistry::report() const 
{
    std::scoped_lock lock(_mtx);
    std::cout << "\n--- CPU Profiler Report --\n";
    for (auto const& [name, entry] : _data)
    {
        double avg = entry.totalTime / entry.callCount;
        std::cout << std::setw(40) << std::left << name
                << " | total: " << std::setw(10) << std::right
                << entry.totalTime << " ms | calls: "
                << std::setw(5) << entry.callCount
                << " | avg: " << avg << " ms\n";
    }
}

}