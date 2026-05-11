#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int a[5];
    for (int i=0; i<5; ++i) {
        cin >> a[i];
    }

    sort(&a[0], &a[5]);

    int avg, mid;

    avg = accumulate(&a[0], a + 5, 0) / 5;
    mid = a[2];

    cout << avg << '\n' << mid << endl;

    return 0;
}