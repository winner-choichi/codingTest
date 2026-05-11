#include <iostream>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    int a[n];
    for (int i=0; i<n; ++i) {
        a[i] = i + 1;
    }

    for (int i=0; i<m; ++i) {
        int first, second, temp;
        cin >> first >> second;

        temp = a[first-1];
        a[first-1] = a[second-1];
        a[second-1] = temp;
    }

    for (int i=0; i<n; ++i) {
        cout << a[i] << " ";
    }

    return 0;
}