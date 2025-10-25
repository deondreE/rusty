#pragma once
#include <chrono>
#include "profiler/FixedString.hpp"
#include "profiler/ProfilerRegistry.hpp"

namespace profiler {

template <FixedString Name>
class ProfileScope {
public:
  ProfileScope() :
    _start(std::chrono::steady_clock::now()) {}
  
  ~ProfileScope() noexcept 
  {
    using namespace std::chrono;
    const auto end = steady_clock::now();
    double ms = duration_cast<microseconds>(end-_start).count() / 1000.0;
    ProfilerRegistry::instance().record(Name, ms);
  }

private:
  std::chrono::steady_clock::time_point _start;
};

}