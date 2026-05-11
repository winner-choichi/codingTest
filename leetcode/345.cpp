class Solution {
public:
    string reverseVowels(string s) {
        stack<char> vowels;
        set<char> vowels_set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        for (char c : s) {
            if (vowels_set.count(c) != 0) vowels.push(c);
        }

        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (vowels_set.count(s[i]) != 0) {
                res.push_back(vowels.top());
                vowels.pop();
            }
			else {
                res.push_back(s[i]);
			}
        }
        return res;
    }
};
