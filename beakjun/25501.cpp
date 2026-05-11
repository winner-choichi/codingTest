#include <iostream>
#include <string>
#include <utility>
using namespace std;

pair<int, int> is_palindrome(const string& s, int l, int r, int count) {
    if (l >= r) {
        return {1, count + 1};
    } else if(s[l] != s[r]) {
        return {0, count + 1};
    } else {
        return is_palindrome(s, l+1, r-1, count + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;

        pair<int, int> res = is_palindrome(s, 0, s.length() - 1, 0);

        cout << res.first << " " << res.second << '\n';
    }

    return 0;
}