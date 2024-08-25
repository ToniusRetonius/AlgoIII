// C++ code for the above approach:
#include <iostream>
using namespace std;

// Function to find nth fibonacci number
int fib(int n)
{
    if (n <= 1) {
        return n;
    }
    int x = fib(n - 1);
    int y = fib(n - 2);

    return x + y;
}

// Drivers code
int main()
{
    int n = 5;

    // Function Call
    cout << fib(n);
    return 0;
}
// 0(2^n)