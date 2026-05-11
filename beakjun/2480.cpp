#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int score;

    if (a == b && b == c) {
        score = 10000 + a * 1000;
    } else if (a == b || a == c) {
        score = 1000 + a * 100;
    } else if (b == c) {
        score = 1000 + b * 100;
    } else {
        score = max(a, max(b, c)) * 100;
    }

    cout << score << endl;

    return 0;
}