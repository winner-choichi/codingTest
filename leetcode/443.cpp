class Solution {
public:
    int compress(vector<char>& chars) {
        int c_ptr = 0, w_ptr = 0;
        int len = chars.size();

        while(c_ptr < len) {
            char cc = chars[c_ptr];
            int cnt = 0;

            while (c_ptr < len && cc == chars[c_ptr]) {
                cnt++;
                c_ptr++;
            }

            chars[w_ptr++] = cc;
            if (cnt > 1) {
                string s = to_string(cnt);
                
                for (char c: s) {
                    chars[w_ptr++] = c;
                }
            }
        }

        return w_ptr;
    }
};
