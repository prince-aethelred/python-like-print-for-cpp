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

using namespace std;

/*
int main() {
    double x = 1565.683, y = 85.78, z = 123.982;
    cout << fixed << showpoint;
cout << setprecision(3) << x << ' ';
cout << setprecision(4) << y << ' ' << setprecision(2) << z << endl;
    return 0;
}*/

/*int main() {
    cout << "123456789012345678901234567890" << endl;
cout << setfill('#') << setw(10) << "Mickey"
<< setfill(' ') << setw(10) << "Donald"
<< setfill('*') << setw(10) << "Goofy" << endl;
}*/

/*int main() {
    char ch1, ch2, ch3;
    cin.get(ch1);
    cin.get(ch2);
    cin.get(ch3);

    cout << ch1 << ' ' << ch2 << ' ' << ch3 << endl;
}*/

/*int main() {
    int alpha, beta, gamma;
    cin >> alpha;
    cin.ignore(100, '\n');
    cin >> beta;
    cin.ignore(100,'\n');
    cin >> gamma;

    cout << alpha << ' ' << beta << ' ' << gamma << endl;
}*/

/*int main() {
    int x = 5;
int y = 30;
do
x = x * 2;
while (x < y);

cout << x << endl;
}*/

/*int main() {
    char ch1, ch2;

    cin >> ch1;
    ch2 = cin.peek();
    cin >> ch2;

    cout << ch1 << ' ' << ch2 << endl;
}*/

/*int main() {
    cout << "Sunny " << '\n' << "Day " << endl;
}*/

/*int main() {
    int count = 5;
cout << 'St';
do
{
cout << 'o';
count--;
}
while (count <= 5);
}*/

/*int main() {
    int x;
    double y;

    cin >> x >> y;
    std::cout << x << ' ' << y << std::endl;
}*/

/*int main() {
    int x, y;
    double z;
    cin >> x >> y >> z;
    cout << x << ' ' << y << ' ' << z << endl;
}*/

/*int main() {
    char ch1, ch2;
    int alpha;

    cin.get(ch1);
    cin.get(ch2);
    cin >> alpha;

    cout << ch1 << ' ' << ch2 << ' ' << alpha << endl;
}*/

/*int main() {
int j;
for (j = 10; j <= 10; j++)
cout << j << " ";
cout << j << endl;
}*/

/*int main() {
    int sum = 0;
    int num;
cin >> num;
for (int j = 1; j <= 4; j++)
{
sum = sum + num;
cin >> num;
}
cout << sum << endl;
}*/

/*int main() {
    int alpha = 5;
    int beta = 10;

    alpha = beta--;

    cout << alpha << ' ' << beta << endl;
}*/

/**
    int main() {
        char ch1, ch2;
        cin.get(ch1);
    cin.putback(ch1);
    cin >> ch2;

    std::cout << ch2 << std::endl;
    }
*/

/**
    int main() {
        double x = 1565.683, y = 85.78, z = 123.982;
        cout << fixed << showpoint;
    cout << setprecision(3) << x << ' ';
    cout << setprecision(4) << y << ' ' << setprecision(2) << z << endl;
        return 0;
    }
*/

int main()
{
    cout << "123456789012345678901234567890" << endl;
    cout << setfill('#') << setw(10) << "Mickey"
         << setfill(' ') << setw(10) << "Donald"
         << setfill('*') << setw(10) << "Goofy" << endl;
}
