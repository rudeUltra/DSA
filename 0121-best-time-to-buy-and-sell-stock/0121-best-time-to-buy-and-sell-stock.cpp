class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //basically max difference siu
        //take min from back then minus and store the ans
        int ans=0;
        int mn=prices[0];
        for(int i=1;i<prices.size();++i){
            mn=min(mn,prices[i]);
            ans=max(ans,(prices[i]-mn));
        }
        return ans;
        //basically buy the cheapest stock siuu
    }
};