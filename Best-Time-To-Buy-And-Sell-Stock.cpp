class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pmax{};
        int pmin{INT_MAX};
        for(const auto& price: prices) {
            pmin = min(pmin, price);
            pmax = max(pmax, price - pmin);
        }
        return pmax;
    }
};
