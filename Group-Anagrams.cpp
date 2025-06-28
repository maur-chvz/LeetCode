class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(const auto& s : strs) {
            string temp(26, '0');
            for(const auto& ch : s) {
                temp[ch - 'a'] += 1;
            }
            m[temp].push_back(s);
        }

        vector<vector<string>> out;
        for(const auto& x : m) {
            out.push_back(x.second);
        }
        return out;
    }
};
