class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
	    unordered_map<int, int> mp;

	    for (int i: arr) mp[i]++;

	    unordered_map<int, int> unique_cnt;

	    for (auto [num, cnt]: mp) {
		    if (!unique_cnt.count(cnt)) unique_cnt[cnt] = num;
		    else return false;
	    }

	    return true;
        
    }
};


