class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 1) {return nums[0];}

        int max_val{};
        for(auto const& x : nums) {
            max_val = max(max_val, x);
        }

        vector<int> dp(max_val + 1, 0);
        for(auto const& x : nums) {
            dp[x] += x;
        }
        
        dp[1] = max(dp[0], dp[1]);

        for(int i = 2; i < dp.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + dp[i]);
        }
        return dp.back();
    }
};
