#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    int a[n];
    for (int i=0; i<n; ++i) {
        a[i] = i + 1;
    }

    while (m--) {
        int start, end;
        cin >> start >> end;

        reverse(a + start - 1, a + end);
    }

    for (int i=0; i<n; ++i) {
        cout << a[i] << " ";
    }

    return 0;
}