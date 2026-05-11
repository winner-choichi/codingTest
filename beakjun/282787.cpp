#include <iostream>
#include <vector>
using namespace std;

struct mystack {
    vector<int> data;
    void push(int x) {
        data.push_back(x);
    }

    int pop() {
        if (data.empty()) return -1;

        int x = data.back();
        data.pop_back();

        return x;
    }

    int size() const {
        return data.size();
    }

    bool is_empty() const {
        return data.empty();
    }

    int top() const {
        if (data.empty()) return -1;
        return data.back();
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    mystack stk;
    while(n--) {
        int f;
        cin >> f;
        if (f==1) {
            int input;
            cin >> input;
            stk.push(input);
        } else if (f==2) {
            cout << stk.pop() << '\n';
        } else if (f==3) {
            cout << stk.size() << '\n';
        } else if (f==4) {
            cout << stk.is_empty() << '\n';
        } else if (f==5) {
            cout << stk.top() << '\n';
        }
    }


    return 0;
}