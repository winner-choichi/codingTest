class Solution {
public:
    string reverseWords(string s) {
        string res;

        int i=s.size()-1;

        while(i>=0){
            if(s[i] == ' ') {
                i--;
                continue;
            }
            int j = i;
            while(i>=0 && s[i] != ' ') i--;
            
            if(!res.empty()) res+=' ';
            res+=s.substr(i+1, j-i);
            // cout << i << ' ' << j << ' ' << res << '\n';
        }
        return res;
        
    }
};

