#ifndef TIMER_HPP
#define TIMER_HPP

#include <string>
#include <memory>
#include <chrono>
#include <iostream>

namespace timer
{
    
    struct TimerData
    {
        TimerData()
        {
            t_construct = std::chrono::system_clock::now();
        }
        std::chrono::system_clock::time_point t_construct;
    };
    
    class Timer
    {
    public:
        Timer(const std::string& message = "timer", bool show_destruction_message = true) : message_(message), show_destruction_message_(show_destruction_message)
        {
            data_ = std::make_shared<TimerData>();
        }
        
        ~Timer()
        {
            if (show_destruction_message_)
            {
                const auto t_destruct = std::chrono::system_clock::now();
                std::cout << "[" << message_ << " : \t" << std::chrono::duration_cast<std::chrono::milliseconds>(t_destruct - data_->t_construct).count() << " ms]" << std::endl;
            }
        }
        
        void set_message(const std::string& message) { this->message_ = message; }
        
        long get_elapsed_time_in_milliseconds() const
        {
            const auto t_now = std::chrono::system_clock::now();
            return std::chrono::duration_cast<std::chrono::milliseconds>(t_now - data_->t_construct).count();
        }

    private:
        std::string message_;
        const bool show_destruction_message_;
        std::shared_ptr<TimerData> data_;
    };
}

#endif // TIMER_HPP
