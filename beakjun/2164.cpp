#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> q;

    int n;
    cin >> n;

    for (int i=1; i<n+1; ++i) {
        q.push(i);
    }

    bool flag = true;
    while (q.size() > 1) {
        if (flag) {
            q.pop();
            flag = false;
        } else {
            int temp = q.front();
            q.pop();
            q.push(temp);
            flag = true;
        }

    }

    cout << q.front() << '\n';

    return 0;
}