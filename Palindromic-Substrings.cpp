class Solution {
public:
    vector<string> getSubString(string& s) { // gets every substring
        vector<string> sub{};
        for(int i = 0; i < s.length(); ++i) {
            string temp{};
            for(int j = i; j < s.length(); ++j) {
                temp += s[j];
                sub.push_back(temp);
            }
        }
        return sub;
    }

    int checkPalindrome(const string& s) {
        string temp = s;
        for(int i = s.length() - 1, j = 0; i >= 0; i--, j++) { // iterate through original string backwards and copied string forwards
            if(temp[j] != s[i]){return 0;}
        }
        return 1;
    }

    int countSubstrings(string s) {
        vector<string> subs = getSubString(s);
        int count{};
        for(const auto& x: subs) {
            count += checkPalindrome(x);
        }

        return count;
    }
};
