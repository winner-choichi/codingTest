#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

bool is_num_char(const string& s);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> num_to_name(n + 1);
    unordered_map<string, int> name_to_num;

    for (int i=1; i<n+1; ++i) {
        string s;
        cin >> s;
        num_to_name[i] = s;
        name_to_num[s] = i;
    }

    while(m--) {
        string s;
        cin >> s;
        if (is_num_char(s)) {
            cout << num_to_name[stoi(s)] << '\n';
        } else {
            cout << name_to_num[s] << '\n';
        }
    }


    return 0;
}

bool is_num_char(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if ('0' <= c && '9' >= c) {
            continue;
        }

        return false;
    }

    return true;
}