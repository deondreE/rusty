#pragma once
#include <unordered_map>
#include <string>
#include <mutex>
#include <iostream>

namespace profiler {

struct ProfileEntry {
    double totalTime = 0.0;
    std::size_t callCount = 0;
}; 

class ProfilerRegistry {
public:
    static ProfilerRegistry& instance();
    
    void record(std::string_view name, double ms);
    void report() const;
private:
    std::unordered_map<std::string, ProfileEntry> _data;
    mutable std::mutex _mtx;
};

}