class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0) {break;}
            if(i > 0 && nums[i - 1] == nums[i]) {continue;}

            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if(total < 0) {
                    ++j;
                }
                else if(total > 0) {
                    --k;
                }
                else {
                    out.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while(nums[j] == nums[j - 1] && j < k) {++j;}
                }
            }
        }
 
        return out;
    }
};
