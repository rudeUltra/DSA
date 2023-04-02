class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //worst case O(n^2)
        
        
        //binary search O(nlogm)
        
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        
        vector<int>ans(n,0);
        
        for(int i=0;i<n;++i){
            //binary search
            int low=0;
            int high=m-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                
                if((1ll)*((1ll)*potions[mid]*(1ll)*spells[i])>=success){
                    //atleast
                    high=mid-1; //find a better ans
                }
                else{
                    low=mid+1; //too smol sed
                }
            }
            ans[i]=m-(low);
        }
        
        return ans;
    }
};