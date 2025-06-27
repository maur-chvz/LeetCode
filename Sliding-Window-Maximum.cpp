class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1){return nums;}        
       
        deque<int> d{};
        vector<int> out;
        for(int i = 0; i < nums.size(); ++i) {
            
            while(!d.empty() && nums[i] > d.back()) {d.pop_back();}
            d.push_back(nums[i]);

            if(i >= k && d.front() == nums[i-k]) {
                d.pop_front();
            }

            if(k - i <= 1) {
                out.push_back(d.front());
            }
            
        }
        return out;
    }
};
