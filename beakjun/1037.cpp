#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[50];
    for (int i=0; i<n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
    }

    sort(a, a+n);

    cout << a[0] * a[n-1] << '\n';

    return 0;
}