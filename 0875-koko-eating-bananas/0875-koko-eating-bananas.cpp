class Solution {
public:
    bool isvalid(int k,vector<int>&piles,int h){
        long long count=0; //days
        for(int i=0;i<piles.size();++i){
            if(piles[i]<=k){
                count++;
            }
            else{
                count+=piles[i]/k;
                if(piles[i]%k!=0){
                    count++;
                }
            }
        }
        
        return count<=h;
    }
    
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int mx=INT_MIN;
        for(int i=0;i<n;++i){
            mx=max(mx,piles[i]);
        }
        
        int low=1;
        int high=mx;
        int ans=0;
        while(low<=high){
            //siu
            int mid=low+(high-low)/2;
            
            if(isvalid(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};