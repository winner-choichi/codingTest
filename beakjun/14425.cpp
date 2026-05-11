#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    unordered_set<string> a;

    while (n--) {
        string s;
        cin >> s;
        a.insert(s);
    }

    int cnt = 0;
    while (m--) {
        string s;
        cin >> s;
        if (a.find(s) != a.end()) {
            ++cnt;
        }
    }

    cout << cnt << '\n';

    return 0;
}