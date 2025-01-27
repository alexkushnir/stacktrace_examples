#include <iostream>
#include <boost/stacktrace.hpp>
#include <boost/exception/all.hpp>

using traced = boost::error_info<struct tag_stacktrace, boost::stacktrace::stacktrace>;

template <class Exception>
void Throw(const Exception& e)
{
    throw boost::enable_error_info(e) << traced(boost::stacktrace::stacktrace());
}

void simple_thrower()
{
    throw std::runtime_error("Throwed from thrower\n");
}

void thrower_with_exception_type()
{
    int i = 5;
        if (i >= 4)
            Throw(std::out_of_range("'i' must be less than 4 in oops()"));
        if (i <= 0)
            Throw(std::logic_error("'i' must be greater than zero in oops()"));
}

int main()
{
    try
    {
        simple_thrower();
    }
    catch(const std::exception& e)
    {
        auto backtrace = boost::stacktrace::stacktrace::from_current_exception();
        std::cerr << "Caught exception: " << e.what() << "backtrace is: \n" << backtrace << "\n";
    }

    try
    {
        thrower_with_exception_type();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        const auto* stacktrace = boost::get_error_info<traced>(e);
        if (stacktrace) 
        {
            std::cerr << *stacktrace << "\n";
        }
    }
    
    return 0;
}