class Solution {
public:
    string makeLargestSpecial(string s) {
        int special{};
        int sbegin{};
        vector<string> out;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '1') {++special;}
            else {--special;}
            if(special == 0) {
                string sub = s.substr(sbegin + 1, i - sbegin - 1);
                out.push_back('1' + makeLargestSpecial(sub) + '0');
                sbegin = i + 1;
            }
        }
        sort(out.begin(), out.end(), greater<string>());
        string largest{};
        for(auto const& s : out) {largest += s;}
        return largest;
    }
};
