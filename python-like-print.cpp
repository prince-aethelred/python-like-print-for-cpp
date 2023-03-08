/*Write a robust C++ print function that replicates the versatility of the print function in Python.
It should be able to handle any data type, including generic data types and have a simple, intuitive syntax
that closely mirrors the syntax of Python's print function.*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <type_traits>
#include <list>
#include <array>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>


// This code checks if T is a string, bool, char, wchar_t, char16_t, char32_t, signed char,
// unsigned char, short, unsigned short, int, unsigned int, long, unsigned long, long long,
// unsigned long long, float, double, long double, pointer, member pointer,
// member function pointer, array, or has begin() and end() methods.
template <typename T>
struct is_container
{
    static constexpr bool value =
        std::is_same_v<T, std::remove_cv_t<T>> &&
        !std::is_same_v<T, std::string> &&
        !std::is_same_v<T, bool> &&
        !std::is_same_v<T, char> &&
        !std::is_same_v<T, wchar_t> &&
        !std::is_same_v<T, char16_t> &&
        !std::is_same_v<T, char32_t> &&
        !std::is_same_v<T, signed char> &&
        !std::is_same_v<T, unsigned char> &&
        !std::is_same_v<T, short> &&
        !std::is_same_v<T, unsigned short> &&
        !std::is_same_v<T, int> &&
        !std::is_same_v<T, unsigned int> &&
        !std::is_same_v<T, long> &&
        !std::is_same_v<T, unsigned long> &&
        !std::is_same_v<T, long long> &&
        !std::is_same_v<T, unsigned long long> &&
        !std::is_same_v<T, float> &&
        !std::is_same_v<T, double> &&
        !std::is_same_v<T, long double> &&
        !std::is_pointer_v<T> &&
        !std::is_member_pointer_v<T> &&
        !std::is_member_function_pointer_v<T> &&
        std::is_array_v<T> == false &&
        requires(T t) {
            {t.begin()} -> std::same_as<typename T::iterator>;
            {t.end()} -> std::same_as<typename T::iterator>;
        };
};


template <typename T>
void print_container(const T& container)
{
    if constexpr (is_container<T>::value) {
        std::cout << "[";
        auto it = container.begin();
        if (it != container.end()) {
            std::cout << *it;
            ++it;
        }
        for (; it != container.end(); ++it) {
            std::cout << ", " << *it;
        }
        std::cout << "]" << std::endl;
    } else {
        std::cout << container << std::endl;
    }
}

template <typename... Ts>
void print_container(const Ts&... containers)
{
    std::apply([](const auto&... args) {
        ((print_container(args)), ...);
    }, std::tuple<const Ts&...>(containers...));
}

int main()
{
    std::vector<int> vec = {1, 2, 3};
    std::deque<double> deq = {1.0, 2.0, 3.0};
    std::list<char> lst = {'a', 'b', 'c'};
    int a = 10;
    const char *str = "hello";
    double d = 3.14159;
    std::string str2 = "std::hello";

    print_container(a, lst, str, str2, deq, vec);

    return 0;
}

//Output:

//[10, [a, b, c], hello, std::hello, [1, 2, 3], [1, 2, 3]]