// #include <stdexcept>    // std::logic_error
#include <iostream>     // std::cerr
#include <boost/stacktrace.hpp>
#include <boost/assert.hpp>

namespace boost 
{
    inline void assertion_failed_msg(char const* expr, char const* msg, char const* function, char const* /*file*/, long /*line*/) 
    {
        std::cerr << "Expression '" << expr << "' is false in function '" << function << "': " << (msg ? msg : "<...>") << ".\n"
            << "Backtrace:\n" << boost::stacktrace::stacktrace() << '\n';
    }

    inline void assertion_failed(char const* expr, char const* function, char const* file, long line) 
    {
        ::boost::assertion_failed_msg(expr, nullptr, function, file, line);
    }
} 

int main()
{
    BOOST_ASSERT(0 == 1);
    BOOST_ASSERT_MSG(0 == 1, "0 != 1");
 
    return 0;
}