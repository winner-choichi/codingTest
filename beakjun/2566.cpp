#include <iostream>
using namespace std;

int main() {
    int max_val = -1, max_row, max_col;

    for (int i=1; i<10; ++i) {
        for (int j=1; j<10; ++j) {
            int input;
            cin >> input;
            if (max_val < 0 || input >= max_val) {
                max_val = input;
                max_row = i;
                max_col = j;
            }
        }
    }

    cout << max_val << '\n' << max_row << " " << max_col << endl;
    return 0;
}