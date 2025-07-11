class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for(auto const& x : rods) {
            unordered_map<int, int> curr(dp);
            for(auto const& it : curr) {
                int d = it.first;
                dp[d + x] = max(dp[d + x], curr[d]);
                dp[abs(d - x)] = max(dp[abs(d - x)], curr[d] + min(d, x));
            }
        }
        return dp[0];
    }
};
