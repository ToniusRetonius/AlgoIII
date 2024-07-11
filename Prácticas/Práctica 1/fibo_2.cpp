// C++ code for the above approach:
#include <iostream>
using namespace std;

// Helper Function
int fibo_helper(int n, int* ans)
{

    // Base case
    if (n <= 1) {
        return n;
    }

    // To check if output already exists
    if (ans[n] != -1) {
        return ans[n];
    }

    // Calculate output
    int x = fibo_helper(n - 1, ans);
    int y = fibo_helper(n - 2, ans);

    // Saving the output for future use
    ans[n] = x + y;

    // Returning the final output
    return ans[n];
}

int fibo(int n)
{
    int* ans = new int[n + 1];

    // Initializing with -1
    for (int i = 0; i <= n; i++) {
        ans[i] = -1;
    }
    fibo_helper(n, ans);
}

// Drivers code
int main()
{
    int n = 5;

    // Function Call
    cout << fibo(n);
    return 0;
}
// O(n) con memoizacion approach top-down