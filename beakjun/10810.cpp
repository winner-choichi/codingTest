#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[n];
    for (int i=0; i<n; ++i) {
        a[i] = 0;
    }

    while (m--) {
        int start, end, num;

        cin >> start >> end >> num;

        for (int j=start-1; j<end; ++j){
            a[j] = num;
        }

    }

    for (int i=0; i<n; ++i) {
        cout << a[i] << " ";
    }

    return 0;
}