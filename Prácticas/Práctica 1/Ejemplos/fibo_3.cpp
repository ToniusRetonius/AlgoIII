// C++ code for the above approach:
#include <iostream>
using namespace std;

// Function for calculating the nth Fibonacci number
int fibo(int n)
{
    int prevPrev, prev, curr;

    // Storing the independent values
    prevPrev = 0;
    prev = 1;
    curr = 1;

    // Using the bottom-up approach
    for (int i = 2; i <= n; i++) {
        curr = prev + prevPrev;
        prevPrev = prev;
        prev = curr;
    }

    // Returning the final answer
    return curr;
}

// Drivers code
int main()
{
    int n = 5;

    // Function Call
    cout << fibo(n);
    return 0;
}
// O(1) espacial Bottom-Up