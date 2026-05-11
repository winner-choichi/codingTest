#include <iostream>
using namespace std;

int main() {
    const int l = 101;
    char a[l];

    cin >> a;

    int length = 0;
    for (int i=0; i<l; ++i) {
        if (a[i] == '\0') {
            length = i;
            break;
        }

    }

    cout << length << endl;

    return 0;
}