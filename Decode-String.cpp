class Solution {
public:
    string decodeString(string s) {
        stack<string> sub;
        stack<int> times;

        int current_count{};
        string current_string{};

        for(int i = 0; i < s.length(); ++i) {
            if(s[i] - '0' <= 9 && s[i] - '0' >= 0) {
                current_count = current_count * 10 + s[i] - '0';
            }

            else if(s[i]  == '[') {
                times.push(current_count);
                sub.push(current_string);
                current_count = 0;
                current_string = "";
            }

            else if(s[i] == ']') {
                string temp = sub.top();
                sub.pop();
                for(int j = 0; j < times.top(); ++j) {
                    temp += current_string;
                }
                times.pop();
                current_string = temp;
            }

            else {
                current_string += s[i];
            }
        }
        return current_string;
    }
};
