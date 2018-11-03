/*
 MIT License
 
 Copyright (c) 2018 Yuki Koyama
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#ifndef TIMER_HPP
#define TIMER_HPP

#include <string>
#include <memory>
#include <chrono>
#include <iostream>

namespace timer
{
    class Timer
    {
    public:
        Timer(const std::string& message = "timer", bool show_destruction_message = true) :
        message_(message),
        show_destruction_message_(show_destruction_message),
        t_construct_(std::chrono::system_clock::now())
        {
        }
        
        ~Timer()
        {
            if (show_destruction_message_)
            {
                const auto t_destruct = std::chrono::system_clock::now();
                std::cout << "[" << message_ << " : \t" << std::chrono::duration_cast<std::chrono::milliseconds>(t_destruct - t_construct_).count() << " ms]" << std::endl;
            }
        }
        
        void set_message(const std::string& message) { this->message_ = message; }
        
        long get_elapsed_time_in_milliseconds() const
        {
            const auto t_now = std::chrono::system_clock::now();
            return std::chrono::duration_cast<std::chrono::milliseconds>(t_now - t_construct_).count();
        }

    private:
        std::string message_;
        const bool show_destruction_message_;
        const std::chrono::system_clock::time_point t_construct_;
    };
}

#endif // TIMER_HPP
