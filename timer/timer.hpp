#ifndef TIMER_HPP
#define TIMER_HPP

#include <string>
#include <memory>

struct TimerData;

class Timer
{
public:
    Timer(const std::string& message = "timer", bool show_destruction_message = true);
    ~Timer();

    void set_message(const std::string& message) { this->message_ = message; }
    long get_elapsed_time_in_milliseconds() const;

private:
    std::string message_;
    const bool show_destruction_message_;
    std::shared_ptr<TimerData> data_;
};

#endif // TIMER_HPP
