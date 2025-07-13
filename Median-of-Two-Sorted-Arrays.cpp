class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left{};
        int right{m};

        while(left <= right) {
            int part1 = (left + right) >> 1;
            int part2 = ((m + n + 1) >> 1) - part1;

            int left_max1 = (part1 == 0) ? INT_MIN : nums1[part1- 1];
            int right_min1 = (part1 == m) ? INT_MAX : nums1[part1];
            int left_max2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
            int right_min2 = (part2 == n) ? INT_MAX : nums2[part2];

            if(left_max1 <= right_min2 && left_max2 <= right_min1) {
                if((m + n) % 2 == 0) {
                    return (max(left_max1, left_max2) + min(right_min1, right_min2)) / 2.0;
                }
                else {
                    return max(left_max1, left_max2);
                }
            }
            else if(left_max1 <= right_min2) {
                left = part1 + 1;
            }
            else {
                right = part1 - 1;
            }
        }
        return 0.0;
    }
};
