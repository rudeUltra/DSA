class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        int mn=INT_MAX;
        for(int i=0;i<n;++i){
            mn=min(mn,prices[i]);
            profit=max(profit,prices[i]-mn);
        }
        return profit;
    }
};