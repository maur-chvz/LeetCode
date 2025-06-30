class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int out{};
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > prices[i - 1]) {
                out += prices[i] - prices[i - 1];
            }
        }
        return out;
    }
};
