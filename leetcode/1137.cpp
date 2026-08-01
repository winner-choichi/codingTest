class Solution {
public:
    int tribonacci(int n) {
        vector<int> tribonacci = {0, 1, 1};
        tribonacci.reserve(n+1);

        for(int i=3; i<=n; i++) {
            tribonacci.push_back(tribonacci[i-3] + tribonacci[i-2] + tribonacci[i-1]);
        }

        return tribonacci[n];
    }
};
