class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mprofit{};
        int last{prices[0]};
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > last) {
                mprofit += prices[i] - last;
            }
            last = prices[i];
        }
        return mprofit;
    }
};
