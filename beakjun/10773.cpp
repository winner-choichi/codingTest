#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, sum = 0;
    cin >> k;

    stack<int> s;
    while (k--) {
        int input;
        cin >> input;

        if (input == 0) {
            s.pop();
        } else {
            s.push(input);
        }
    }

    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum << '\n';


    return 0;
}