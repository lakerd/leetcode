class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int stocks0 = 0;
        int stocks1 = INT_MIN;
        for (int price : prices) {
            int old = stocks0;
            stocks0 = max(stocks0, stocks1 + price);
            stocks1 = max(stocks1, old - price);
        }
        
        return stocks0;
    }
};

