#include <iostream>
using namespace std;

int main() {
    bool a[100][100];
    for (int r=0; r<100; ++r) {
        for (int c=0; c<100; ++c) {
            a[r][c] = false;
        }
    }

    int input_size;
    cin >> input_size;

    while(input_size--) {
        int x, y;
        cin >> y >> x;

        for (int i=x; i<x+10; ++i) {
            for (int j=y; j<y+10; ++j) {
                a[i][j] = true;
            }
        }
    }

    int cnt = 0;
    for (int r=0; r<100; ++r) {
        for (int c=0; c<100; ++c) {
            if (a[r][c] == true) {
                ++cnt;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}