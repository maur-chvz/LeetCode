class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int out{1};
        int dp1{1};
        int dp2{1};
        for(int i = 1; i < nums1.size(); ++i) {
            int t11 = nums1[i - 1] <= nums1[i] ? dp1 + 1 : 1;
            int t12 = nums1[i - 1] <= nums2[i] ? dp1 + 1 : 1;
            int t21 = nums2[i - 1] <= nums1[i] ? dp2 + 1 : 1;
            int t22 = nums2[i - 1] <= nums2[i] ? dp2 + 1 : 1;
            dp1 = max(t11, t21);
            dp2 = max(t12, t22);
            out = max(out, max(dp1, dp2));
        }
        return out;
    }
};
