#include <iostream>
#include <string>
#include <vector>
using namespace std;



struct myqueue {
    vector<int> v;
    int head=0;

    void push(int x) {
        v.push_back(x);
    }

    int pop() {
        if (v.size() == head) {
            return -1;
        } else {
            ++head;
            return v[head-1];
        }
    }

    int size() const {
        return v.size() - head;
    }

    bool empty() const {
        return v.size() == head;
    }

    int front() const {
        if (v.size() == head) {
            return -1;
        } else {
            return v[head];
        }
    }
    
    int back() const {
        if (v.size() == head) {
            return -1;
        } else {
            return v[v.size()-1];
        }
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    myqueue myq;

    while (n--) {
        string s;
        cin >> s;

        if (s == "push") {
            int x;
            cin >> x;
            myq.push(x);
        } else if (s == "pop") {
            cout << myq.pop() << "\n";
        } else if (s == "size") {
            cout << myq.size() << '\n';
        } else if (s == "empty") {
            cout << myq.empty() << '\n';
        } else if (s == "front") {
            cout << myq.front() << '\n';
        } else if (s == "back") {
            cout << myq.back() << '\n';
        }
    }



    return 0;
}