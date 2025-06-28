class Solution {
public:
    int countPalindrome(string_view s, int left, int right) {
        int count{};
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            ++count;
            --left;
            ++right;
        }
        return count;
    }

    int countSubstrings(string s) {
        int count{};
        for(int i = 0; i < s.size(); ++i) {
            count += countPalindrome(s, i, i);
            count += countPalindrome(s, i, i+1);
        }
        return count;
    }
};
