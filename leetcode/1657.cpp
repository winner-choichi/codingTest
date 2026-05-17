class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        if (l1!=l2) return false;
        unordered_map<char, int> chars_1, chars_2;

        for (char c: word1) {
            if (chars_1.count(c) == 0) chars_1[c] = 1;
            else chars_1[c]+=1;
        }

        for (char c: word2) {
            if (chars_2.count(c) == 0) chars_2[c] = 1;
            else chars_2[c]+=1;
        }

        for (auto [c, n]: chars_1) {
            if (chars_2.count(c) == 0) return false;
        }

        unordered_map<int, vector<char>> cnt_chars_1, cnt_chars_2;

        for (auto [c, n]: chars_1) {
            if (cnt_chars_1[n].empty()) cnt_chars_1[n] = vector<char>(1, c);
            else cnt_chars_1[n].push_back(c);
        }

        for (auto [c, n]: chars_2) {
            if (cnt_chars_2[n].empty()) cnt_chars_2[n] = vector<char>(1, c);
            else cnt_chars_2[n].push_back(c);
        }

        for (auto [n, v]: cnt_chars_1) {
            if (v.size() != cnt_chars_2[n].size()) return false;
        }
        return true;
    }
};

