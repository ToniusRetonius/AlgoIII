#include<iostream>
#include<string>
using namespace std;

bool rEq(string a, string b) {
    if (a == b)
        return true;

    if (a.length() == 1 && b.length() == 1)
        return a == b;
    
    if (a.length() % 2 == 0) {
        int m = a.length() / 2;
        string a1 = a.substr(0, m);
        string a2 = a.substr(m);
        string b1 = b.substr(0, m);
        string b2 = b.substr(m);
        return ((rEq(a1, b2) && rEq(a2, b1)) || (rEq(a1, b1) && rEq(a2, b2)));
    }
    return false;
}

int main() {
    string a, b;
    cin >> a >> b;
    if (rEq(a, b))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
