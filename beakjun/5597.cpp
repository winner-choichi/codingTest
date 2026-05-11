#include <iostream>
using namespace std;

int main() {
    const int num = 30;

    int a[num];

    for (int i=0; i<num; ++i) {
        a[i] = 0;
    }

    for (int i=0; i<num - 2; ++i) {
        int input;
        cin >> input;
        a[input - 1] = input;
    }

    int first = 0, second = 0;
    for (int i=0; i<num; ++i) {
        if (a[i] == 0) {
            if (first == 0) {
                first = i + 1;
            } else {
                second = i + 1;
            }
        }
    }

    cout << first << " " << second;
    

    return 0;
}