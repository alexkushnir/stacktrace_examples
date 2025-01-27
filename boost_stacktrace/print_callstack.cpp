#include <iostream>

#include <boost/stacktrace.hpp>

void foobar()
{
    std::cout << boost::stacktrace::stacktrace() << "\n";
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