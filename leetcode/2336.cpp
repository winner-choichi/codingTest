class SmallestInfiniteSet {
public:
    set<int> popped_nums;
    int popped_local_max;
    SmallestInfiniteSet() {
        this->popped_local_max = 0;
    }
    
    int popSmallest() {
        this->popped_nums.insert(++this->popped_local_max);
        int popped_num = this->popped_local_max;
        while(this->popped_nums.contains(this->popped_local_max+1)) this->popped_local_max++;
        return popped_num;
    }
    
    void addBack(int num) {
        if (!this->popped_nums.contains(num)) return;

        this->popped_nums.erase(num);
        if (num <= this->popped_local_max) this->popped_local_max = num - 1;
        cout << this->popped_local_max << '\n';
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

