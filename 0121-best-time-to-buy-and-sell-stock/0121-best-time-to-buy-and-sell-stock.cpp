class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int maxProfit=0;
        int lowestTillday=prices[0];
        for(int i=0;i<n;i++){
            lowestTillday=min(prices[i],lowestTillday);
            int ProfitSellToday=(prices[i]-lowestTillday);
            maxProfit=max(maxProfit,ProfitSellToday);
        }
        return maxProfit;
        
    }
};