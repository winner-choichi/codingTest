class SmallestInfiniteSet {
public:
    int curr;
    set<int> add_backed_nums;
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        if(!add_backed_nums.empty()) {
            int n = *add_backed_nums.begin();
            add_backed_nums.erase(add_backed_nums.begin());
            return n;
        }

        return curr++;
    }
    
    void addBack(int num) {
        if (num < curr) {
            add_backed_nums.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

