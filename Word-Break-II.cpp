class Solution {
public:
    void backTrack(const string& s, const unordered_set<string>& words, string& current, vector<string>& result, int startIndex) {
        if(startIndex == s.length()) {
            result.push_back(current);
            return;
        }

        for(int endIndex = startIndex + 1; endIndex <= s.length(); ++endIndex) {
            string word = s.substr(startIndex, endIndex - startIndex);
            if(words.find(word) != words.end()) {
                string original = current;
                if(!current.empty()) {current += ' ';}
                current += word;

                backTrack(s, words, current, result, endIndex);
                current = original;
            }
        }
    }

    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        vector<string> result;
        string current;

        backTrack(s, words, current, result, 0);

        return result;
    }
};
