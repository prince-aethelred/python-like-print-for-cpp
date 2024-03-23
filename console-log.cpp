#include <iostream>
#include <vector>
#include <list>
#include <type_traits>
#include <map>
#include <unordered_map>
#include <sstream>
#include <array>

// Typeype trait to check if a type is a container
template <typename Type, typename _ = void>
struct is_container : std::false_type
{
};

template <typename Type>
struct is_container<
    Type,
    std::conditional_t<
        false,
        typename Type::value_type,
        void>> : std::true_type
{
};

template <typename Type>
struct is_map
{
    static const bool value = false;
};

template <typename Key, typename Value>
struct is_map<std::map<Key, Value>>
{
    static const bool value = true;
};

template <typename Key, typename Value>
struct is_map<std::unordered_map<Key, Value>>
{
    static const bool value = true;
};

// Overload of << operator for containers
// Requires the container to have begin() and end() methods
// Requires the container's value_type to have an overloaded << operator
namespace console {
template <typename Type>
typename std::enable_if<is_container<Type>::value && !std::is_same<Type, std::string>::value, std::ostream &>::type
operator<<(std::ostream &output_stream, const Type &input_container)
{
    if (std::is_same<Type, std::string>::value)
    {
        output_stream << input_container;
        return output_stream;
    }
    else
    {
        output_stream << "[";
        for (auto it = input_container.begin(); it != input_container.end(); ++it)
        {
            if (it != input_container.begin())
            {
                output_stream << ", ";
            }
            // output_stream << *it;
            if constexpr (is_map<Type>::value)
            {
                output_stream << it->first << ": ";
                output_stream << it->second;
            }
            else
            {
                output_stream << *it;
            }
        }
        output_stream << "]";
    }
    return output_stream;
}

template <typename Type>
void log(Type &&input)
{
    std::cout << input;
}


template <typename Type, typename... Args>
void log(Type &&input, Args &&...args)
{
    std::cout << input;
    std::cout << " ";;
    log(std::forward<Args>(args)...);
}
}

auto main() -> int
{
    std::ostringstream myout;

    std::unique_ptr<std::string[]> array(new std::string[100'000]);
    for (int i = 0; i < 100'000; i++)
    {
        array[i] = "Hello World!";
        myout << array[i] << " ";
    }
    //std::cout << myout.str();
    console::log(myout.str());

    const char * testch = "hello";
    console::log(testch, 1, 2, 489840, R"(\n)", '\n');

    std::string testr = "hello";
    console::log(testr, "Hello", 1, 2.0, 3.0f);
    //std::cout << testr;
    console::log(testr);

    std::ostringstream oss;
    oss << testr;
    console::log(oss.str());

    std::vector<int> v = {1, 2, 3, 4, 5};
    //std::cout << v << std::endl;
    console::log(v, "Hello", 1, 2.0, 3.0f);

    console::log("\n");
    std::map<int, int> m = {{1, 1}, {2, 1}, {3, 3}};
    console::log(m, "Hello", 1, 2.0, 3.0f);
    console::log("\n");

    console::log(v, m, "Hello", 1, 2.0, 3.0f);
    std::unordered_map<int, int> um = {{1, 1}, {2, 1}, {3, 3}};
    console::log("\n", "Part 2 Bruv", um, "\n", v, m, "Hello", 1, 2.0, 3.0f);

    int num = 5;
    int *num_ptr = &num;

    int(*num_ptr2) = &num;

    console::log("\n", "num: ", num, "*num_ptr: ", *num_ptr, "*num_ptr2: ", (*num_ptr2), "\n");
    return 0;
}