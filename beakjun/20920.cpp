#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    unordered_map<string, int> word_cnt;

    while(n--) {
        string s;
        cin >> s;

        if(s.length() >= m) {
            word_cnt[s]++;
        }
    }

    vector<string> output;
    output.reserve(word_cnt.size());
    for (const auto& [word, cnt]: word_cnt) {
        output.push_back(word);
    }


    sort(output.begin(), output.end(), [&](const string& a, const string& b) {
        if(word_cnt[a] != word_cnt[b]) {
            return word_cnt[a] > word_cnt[b];
        } else if (a.length() != b.length()) {
            return a.length() > b.length();
        } else {
            return a < b;
        }
    });

    for (const auto& w: output) {
        cout << w << '\n';
    }

    return 0;
}