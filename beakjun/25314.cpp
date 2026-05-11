#include <iostream>
using namespace std;

int main() {
    int num_byte;

    cin >> num_byte;

    for (int i = 0; i < num_byte / 4; ++i) {
        cout << "long" << " ";
    }

    cout << "int" << endl;

    return 0;
}