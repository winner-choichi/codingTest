#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> myqueue, output;

    int n, k;
    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
        myqueue.push(i);
    }

    int i = 1;
    while (!myqueue.empty()) {
        if (i%k == 0) {
            output.push(myqueue.front());
            myqueue.pop();
        } else {
            int temp = myqueue.front();
            myqueue.pop();
            myqueue.push(temp);
        }

        ++i;
    }

    cout << '<';
    while (!output.empty()) {
        if (!(output.size() == 1)){
            cout << output.front() << ", ";
        } else {
            cout << output.front();
        }
        output.pop();
    }

    cout << ">" << '\n';

    return 0;
}