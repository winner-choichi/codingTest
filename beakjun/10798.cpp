#include <iostream>
using namespace std;

int main() {
    char a[5][15];
    for (int i=0; i<5; ++i) {
        for (int j=0; j<15; ++j) {
            a[i][j] = '@';
        }
    }

    int max_length = 0;
    for (int i=0; i<5; ++i) {
        int j = 0;
        while (1) {
            char input;
            cin >> noskipws >> input;
            if (input == '\n') {
                break;
            } else {
                a[i][j] = input;
                ++j;
            }
        }

        if (j > max_length) {
            max_length = j;
        }
    }

    for (int c=0; c<max_length; ++c) {
        for (int r=0; r<5; ++r) {
            if (a[r][c] != '@') {
                cout << a[r][c];
            }
        }
    }
    cout << endl;

    return 0;
}