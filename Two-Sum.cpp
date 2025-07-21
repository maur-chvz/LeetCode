class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() == 2) {return {0, 1};}
        unordered_map<int, int> dp;
        
        for(int i = 0; i < nums.size(); ++i) {
            int second = target - nums[i];
            if(dp.find(second) != dp.end()) {return {i, dp[second]};}
            dp[nums[i]] = i;
        }
        return {-1, -1};
    }
};
