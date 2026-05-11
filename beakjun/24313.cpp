#include <iostream>
using namespace std;

int main() {
    int a_0, a_1, c, n_0;

    cin >> a_0 >> a_1 >> c >> n_0;

    if (n_0 * c >= n_0 * a_0 + a_1 && a_0 <= c) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}