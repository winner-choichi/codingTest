class Solution {
public:
    bool is_vowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    int maxVowels(string s, int k) {
        int len = s.size();
        int max=0;

        int window_cnt = 0;
        for (int i=0; i<k; ++i) {
            if (!is_vowel(s[i])) continue;
            window_cnt++;
        }
        if (max<window_cnt) max = window_cnt;
        for (int i=1; i<=len-k; ++i) {
            if (is_vowel(s[i-1])) {
                window_cnt--;
            }
            if (is_vowel(s[i+k-1])) {
                window_cnt++;
            }
            if (max<window_cnt) max = window_cnt;
        }

        return max;
    
    }
};

