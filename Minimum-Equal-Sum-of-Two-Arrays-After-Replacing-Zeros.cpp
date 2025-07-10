class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long max1{};
        long max2{};
        int zeros1{};
        int zeros2{};
        for(int i = 0; i < nums1.size(); ++i) {
            if(nums1[i] == 0) {++zeros1;}
            max1 += nums1[i];
        }
        for(int i = 0; i < nums2.size(); ++i) {
            if(nums2[i] == 0) {++zeros2;}
            max2 += nums2[i];
        }

        long min1 = max1 + zeros1;
        long min2 = max2 + zeros2;

        if(zeros1 == 0 && zeros2 == 0) {return max1 == max2 ? max1 : -1;}
        else if (zeros1 == 0) {return min2 <= max1 ? max1 : -1;}
        else if (zeros2 == 0) {return min1 <= max2 ? max2 : -1;}
        
        return max(min1, min2);
    }
};
