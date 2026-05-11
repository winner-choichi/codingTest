class Solution {
public:
    bool isSubsequence(string s, string t) {
	    int read = 0, compare = 0;
	    int s_size = s.size(), t_size = t.size();

        if (s_size <= 0) return true;
        if (t_size <= 0) return false;

	    while(read < s_size){
		    while(1) {
			    if(s[read] == t[compare]) {
                    if (read == s_size - 1) return true;
                    ++compare;
			        if(compare == t_size) return false;
                    break;
                }
			    ++compare;
			    if(compare == t_size) return false;
		    }
		    ++read;
	    }

	    return true;
        
    }
};

