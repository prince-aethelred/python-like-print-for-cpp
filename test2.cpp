#ifdef __GNUC__
// This block will only be included when using g++, since __GNUC__ is defined by GCC.
#include <bits/stdc++.h>
#endif

#ifdef __clang__
// This block will only be included when using clang++, since __clang__ is defined by Clang.
// Include your individual headers here
#include <iostream>
#include <vector>
#include <iomanip>
#endif

class Calc
{
private:
    int m_value{};

public:
    Calc &add(int value)
    {
        m_value += value;
        return *this;
    }
    Calc &sub(int value)
    {
        m_value -= value;
        return *this;
    }
    Calc &mul(int value)
    {
        m_value *= value;
        return *this;
    }

    int getValue()
    {
        return m_value;
    }
};

int main()
{
    Calc calc{};
    calc.add(5).sub(3).mul(4);
    std::cout << calc.getValue() << std::endl;
    return 0;
}
