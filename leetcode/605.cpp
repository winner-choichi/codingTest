class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) return true;

	int remainder = n;
	int length = flowerbed.size();
		
	for (int i=0; i<length; ++i) {
		if (flowerbed[i] == 1) continue;
		if (i>0 && flowerbed[i-1] == 1) continue;
		if (i<length-1 && flowerbed[i+1] == 1) continue;

		--remainder;
		flowerbed[i] = 1;

		if (remainder <=0) return true;
	}

	return false;
    }
};
