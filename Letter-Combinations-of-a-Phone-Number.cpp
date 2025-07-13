class Solution {
public:
    void dfs(const string& digits, int indx, unordered_map<char, string>& m, string& current, vector<string>& out) {
        if(indx == digits.size()) {
            out.push_back(current);
            return;
        }

        for(auto const& ch : m[digits[indx]]) {
            current.push_back(ch);
            dfs(digits, indx + 1, m, current, out);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {return {};}

        unordered_map<char, string> m{{'2', "abc"},
                                     {'3', "def"},
                                     {'4', "ghi"},
                                     {'5', "jkl"},
                                     {'6', "mno"},
                                     {'7', "pqrs"},
                                     {'8', "tuv"},
                                     {'9', "wxyz"}};
        vector<string> out;
        string current{};
        dfs(digits, 0, m, current, out);
        return out;
    }
};
