class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1) {return heights[0];}

        stack<int> s;
        s.push(-1);        
        int total{};
        heights.push_back(0);
        
        for(int i = 0; i < heights.size(); ++i) {
            while(s.top() != -1 && heights[i] <= heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                total = max(total, h * (i - s.top() - 1));
            }
            s.push(i);
        }

        return total;
    }
};
