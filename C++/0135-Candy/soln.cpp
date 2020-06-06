class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candys(n, 1);
        for(int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) candys[i] = candys[i - 1] + 1;
        }
        for(int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) candys[i] = max(candys[i], candys[i + 1] + 1);
        }
        int ans = 0;
        for(int candy : candys) ans += candy;
        return ans;
    }
};