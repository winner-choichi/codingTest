#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;

    cin >> s;

    string rev = s;
    reverse(rev.begin(), rev.end());

    if (rev == s) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}