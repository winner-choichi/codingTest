class RecentCounter {
public:
    queue<int> pings;
    int time_w = 3000;
    RecentCounter() {
        
    }
    
    int ping(int t) {
	    pings.push(t);
	    while (pings.front() < t - time_w) pings.pop();

	    return pings.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

