#pragma once
#include <array>
#include <algorithm>
#include <string_view>

namespace profiler 
{

template <std::size_t N>
struct FixedString {
    std::array<char, N> data;

    constexpr explicit FixedString(const char (&str)[N]) noexcept {
        std::copy_n(str, N, data.begin());
    }
    
    constexpr explicit operator std::string_view() const noexcept {
        return std::string_view(data.data(), N - 1);
    }

    constexpr auto operator==(const FixedString&) const noexcept -> bool = default;
};

template <FixedString<0> Name> 
struct ScopeTag {
    static constexpr std::string_view value = Name;
};


    
}