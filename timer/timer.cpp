#include "timer.hpp"
#include <chrono>
#include <iostream>

struct TimerData
{
    TimerData()
    {
        t_construct = std::chrono::system_clock::now();
    }
    std::chrono::system_clock::time_point t_construct;
};

Timer::Timer(const std::string& message, bool show_destruction_message) : message_(message), show_destruction_message_(show_destruction_message)
{
    data_ = std::make_shared<TimerData>();
}

Timer::~Timer()
{
    if (show_destruction_message_)
    {
        const auto t_destruct = std::chrono::system_clock::now();
        std::cout << "[" << message_ << " : \t" << std::chrono::duration_cast<std::chrono::milliseconds>(t_destruct - data_->t_construct).count() << " ms]" << std::endl;
    }
}

long Timer::get_elapsed_time_in_milliseconds() const
{
    const auto t_now = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(t_now - data_->t_construct).count();
}
