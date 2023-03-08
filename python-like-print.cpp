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

/*// C++17 fold expression print function
template <typename... Arg_Type>
void print2(Arg_Type &&...args)
{
    (std::cout << ... << std::forward<Arg_Type>(args)) << std::endl;
}



template <typename... Arg_Types>
void print(const Arg_Types &...args)
{
    (std::cout << ... << args) << std::endl;
}

template <typename T>
std::enable_if_t<std::is_object_v<T>, void>
print(const std::vector<T> &v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, " "));
    std::cout << std::endl;
}

template <typename... Arg_Type>
void print_helper(const Arg_Type &&...args)
{
    (std::cout << ... << args) << std::endl;

    print(std::forward<Arg_Type>(args));
}*/

/*template <typename T>
std::enable_if_t<!std::is_arithmetic_v<T>, void>
print(const std::vector<T> &v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, "\n"));
}*/

/*// Base case print function that takes a single argument and prints it
template <typename T>
void print(T arg)
{
    std::cout << arg << std::endl;
}

// Recursive print function that prints multiple arguments of different types
template <typename T, typename... Args>
void print(T arg, Args... args)
{
    std::cout << arg << " ";
    print(args...);
}

// Variadic template function that accepts a generic container and prints its contents
template <template <typename, typename...> class Container, typename T, typename... Args>
void print(Container<T, Args...> &container)
{
    std::stringstream ss;
    ss << "{ ";
    for (auto &&val : container)
    {
        ss << val << ", ";
    }
    ss << "}";
    std::cout << ss.str() << std::endl;
}

// Specialization of the print function for C-style strings
void print(const char *str)
{
    std::cout << str << std::endl;
}*/

/*// Forward declaration of helper functions
template <typename T>
void printImpl(std::ostream &out, const T &arg);

template <typename T>
void printImpl(std::ostream &out, const std::vector<T> &arg);

// Primary template for the print function
template <typename... Args>
void print(Args &&...args)
{
    ((printImpl(std::cout, std::forward<Args>(args))), ...);
    std::cout << std::endl;
}

// Specialization for printing container types
template <typename T>
void printImpl(std::ostream &out, const std::vector<T> &arg)
{
    out << "[ ";
    for (const auto &val : arg)
    {
        printImpl(out, val);
        out << " ";
    }
    out << "]";
}

// Helper function to print a single argument
template <typename T>
void printImpl(std::ostream &out, const T &arg)
{
    //if constexpr (std::is_same_v<T, std::string>)
    //{
    //    out << '"' << arg << '"';
    //}

    out << arg;
}*/

/*// Recursive helper function to print any type of container
template <typename T>
typename std::enable_if<std::is_container<T>::value, void>::type
print_container(const T &container)
{
    std::cout << "[";
    auto it = container.begin();
    if (it != container.end())
    {
        std::cout << *it;
        ++it;
    }
    for (; it != container.end(); ++it)
    {
        std::cout << ", " << *it;
    }
    std::cout << "]";
}*/

/*template <typename Container,
          typename std::enable_if<
              std::is_same<
                  typename Container::iterator,
                  decltype(std::declval<Container>().begin())>::value>::type * = nullptr>
void print_container(const Container &c)
{
    std::cout << "[";
    auto it = c.begin();
    if (it != c.end())
    {
        std::cout << *it;
        ++it;
    }
    for (; it != c.end(); ++it)
    {
        std::cout << ", " << *it;
    }
    std::cout << "]" << std::endl;
}

// Base function that takes a variadic template argument and prints each element
template <typename T>
void print(T &&t)
{
    std::cout << t << std::endl;
}

template <typename T, typename... Args>
void print(T &&t, Args &&...args)
{
    if constexpr (std::is_same<T, Args>)
    {
        print_container(t);
    }
    else
    {
        std::cout << t << " ";
    }
    print(std::forward<Args>(args)...);
}*/

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


/*template <typename T>
void print_container(const T &container)
{
    if constexpr (is_container<T>::value)
    {
        std::cout << "[";
        auto it = container.begin();
        if (it != container.end())
        {
            std::cout << *it;
            ++it;
        }
        for (; it != container.end(); ++it)
        {
            std::cout << ", " << *it;
        }
        std::cout << "]  ";
    }
    else
    {
        std::cout << container << " ";
    }
}


template <typename T>
void print_containerln(const T &container)
{
    print_container(container);
    std::cout << "\n";
}

template <typename... Ts>
void print_container(const Ts &...containers)
{
    std::apply([](const auto &...args)
               { ((print_container(args)), ...); },
               std::tuple<const Ts &...>(containers...));
}

template <typename... Ts>
void print_containerln(const Ts &...containers)
{
    std::apply([](const auto &...args)
               { ((print_containerln(args)), ...); },
               std::tuple<const Ts &...>(containers...));
}*/

// template <typename... Ts>
// auto param_pack_expand(Ts&&... args)
// {
//     return std::make_tuple(std::forward<Ts>(args)...);
// }

// template <typename T>
// void print_container_impl(const T& container)
// {
//     const std::string sep = " "; 
//     const std::string end = ""; 
//     std::ostream & os = std::cout;
//     //bool flush = false;
//     os << "[";
//     auto it = container.begin();
//     if (it != container.end()) {
//         os << *it;
//         ++it;
//     }
//     for (; it != container.end(); ++it) {
//         os << sep << *it;
//     }
//     os << "]" << end;
//     //if (flush) {
//     //    os.flush();
//     //}
// }

// /*template <typename T>
// void indprint_container(const T& container)
// {
//     const std::string sep = " "; 
//     const std::string end = ""; 
//     std::ostream & os = std::cout;
//     bool flush = false;
//     // If T is a container
//     if constexpr (is_container<T>::value) {     
//         print_container_impl(container);
//     } else {
//         os << container << end; // Otherwise print the container and an end line
//         if (flush) {
//             os.flush();
//         }
//     }

//     std::cout << sep;
// }*/


// template <typename T>
// void indprint_container(const T& input, const std::string & sep, std::ostream & os)
// {
//     //const std::string end = ""; 
//     //bool flush = false;

//     if constexpr (is_container<T>::value) {     
//         print_container_impl(input);
//     } else {
//         os << input << sep;
//         //if (flush) {
//         //    os.flush();
//         //}
//     }

//     os << sep;
// }



// template <typename... Ts>
// void print_container(const Ts &... containers, const std::string & sep=" ", const std::string & end="\n", std::ostream & os=std::cout, bool flush=false)
// {
//     std::tuple<const Ts&...> tuple_of_containers(containers...);

//     auto print = [&](const auto&... args) {
//         ( (indprint_container(args, sep, os) ), ...);
//     };

//     std::apply(print, tuple_of_containers);

//     std::cout << "\n";
// }



///////////////////////////
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
    
    //print_container(a, lst, str, str2, deq, vec, " ", "\n", std::cout, true);
    //print_container(vec, );
    //print_container(a);
    //print_container(str);
    //print_container(d);
    //print_container(str2);

    //print_container(vec, deq, lst, a, str, sep=" ", end="\n", os=std::cout, flush=false);

    //print_container(vec, deq, lst);
    //print_container(vec, deq, lst, a, str, d, str2);

    return 0;
}

// int main()
// {
//     /*print("Hello, world!");
//     print(42, "foo", 3.14);
//     print(3.14);
//     std::vector<int> v{1, 2, 3};
//     print(42, v);*/

//     int x = 10;
//     double y = 20.5;
//     char c = 'a';
//     const char *str = "hello world";
//     std::string str2 = "2hello2world";
//     std::vector<int> vec = {1, 2, 3, 4, 5};
//     std::array<int, 3> arr = {1, 2, 3};

//     // print(x, y, c, str, str2, vec, arr);
//     //  print(std::vector<int>{1, 2, 3});
//     //  print(std::vector<std::string>{"foo", "bar", "baz"});
//     //   print(std::array<int, 3>{1, 2, 3});

//     // print2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
//     //  print2(std::vector<int>{1, 2, 3});

//     return 0;
// }

/*#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <map>
#include <tuple>


template <typename T>
void print(T t)
{
    std::cout << t;
}


template <typename T, typename... Args>
void print(T t, Args... args)
{
    std::cout << t;
    print(args...);
}

template <typename T>
void print_iterable(const T &iterable)
{
    std::cout << "[";
    for (const auto &i : iterable)
    {
        print(i, ", ");
    }
    std::cout << "]";
}

template <typename T1, typename T2>
void print_pair(const std::pair<T1, T2> &p)
{
    std::cout << "(" << p.first << ", " << p.second << ")";
}

template <typename... Args>
void print_tuple(const std::tuple<Args...> &t)
{
    std::cout << "(";
    std::apply([](const auto &...args)
               { ((print(args, ", ")), ...); },
               t);
    std::cout << ")";
}

template <typename T>
void print_map(const std::map<std::string, T> &m)
{
    std::cout << "{";
    for (const auto &[k, v] : m)
    {
        std::cout << k << ": ";
        print(v, ", ");
    }
    std::cout << "}";
}

template <typename T>
void print_type(const T &t)
{
    if constexpr (std::is_same<T, std::string>::value)
    {
        std::cout << t;
    }
    else if constexpr (std::is_same<T, char>::value)
    {
        std::cout << t;
    }
    else if constexpr (std::is_arithmetic<T>::value)
    {
        std::cout << t;
    }
    else if constexpr (std::is_same<T, std::vector<typename T::value_type>>::value)
    {
        print_iterable(t);
    }
    else if constexpr (std::is_same<T, std::map<std::string, typename T::mapped_type>>::value)
    {
        print_map(t);
    }
    else if constexpr (std::is_same<T, std::pair<typename T::first_type, typename T::second_type>>::value)
    {
        print_pair(t);
    }
    else if constexpr (std::is_same<T, std::tuple<typename T::value_type...>>::value)
    {
        print_tuple(t);
    }
    else
    {
        std::cout << typeid(t).name();
    }
}

int main()
{
    int i = 10;
    double d = 2.5;
    std::string s = "Hello World";
    std::vector<int> v = {1, 2, 3, 4, 5};

    // calling the custom print function
    print(i);
    print(d);
    print(s);
    print(v);

    return 0;
}
*/
