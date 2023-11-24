class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        
   
        cout<<endl;
        
        int ans=0;
        
        int n=piles.size();
        
        int i=n-2;
        if(n==3){
            return piles[1];
        }
        int required=piles.size()/3;
        int count=0;
        while(count<required){
            cout<<piles[i]<<" ";
            ans+=piles[i];
            i=i-2;
            count++;
        }
        
        return ans;
    }
};