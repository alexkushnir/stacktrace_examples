#include <boost/stacktrace.hpp>
#include <iostream>

void dump_stacktrace_address_and_name(const boost::stacktrace::stacktrace& stacktrace)
{
    for (const auto& frame : stacktrace)
    {
        std::cout << frame.address() << ": " << frame.name() << "\n";
    }
}

void dump_full_stacktrace(const boost::stacktrace::stacktrace& stacktrace)
{
    for (const auto& frame : stacktrace)
    {
        std::cout << frame << "\n";
    }
}

void foobar()
{
    dump_stacktrace_address_and_name(boost::stacktrace::stacktrace());
    std::cout << "\n\n\n";
    dump_full_stacktrace(boost::stacktrace::stacktrace());
}

void bar()
{
    foobar();
}

void foo()
{
    bar();
}

int main() 
{
    foo();
    return 0;
}