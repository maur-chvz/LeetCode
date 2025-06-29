class Solution {
public:
    int trap(vector<int>& height) {
        int count{};
        int left{};
        int right{static_cast<int>(height.size()) - 1};

        int lmax{height[left]};
        int rmax{height[right]};

        while(left < right) {
            if(lmax < rmax) {
                ++left;
                lmax = max(lmax, height[left]);
                count += (lmax - height[left]);
            }
            else {
                --right;
                rmax = max(rmax, height[right]);
                count += (rmax - height[right]);
            }
        }

        return count;
    }
};
