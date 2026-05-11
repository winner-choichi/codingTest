#include <iostream>
using namespace std;

long long int factorial(int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << factorial(n) << '\n';

    return 0;
}


long long int factorial(int x) {
    if (x == 0) {
        return 1;
    } else {
        return factorial(x - 1) * x;
    }
}