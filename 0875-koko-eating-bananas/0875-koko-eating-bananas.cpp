class Solution {
public:
    
    bool isSafe(vector<int>&piles,int target,int mid){
        long long count=0;
        
        for(int i=0;i<piles.size();++i){
            
            if(piles[i]<mid){
                count++;
            }
            else{
                count+=piles[i]/mid;
                if(piles[i]%mid){
                    count++;
                }
            }
        }
        return count<=target;
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
            int mid=low+(high-low)/2;
          
            
            if(isSafe(piles,h,mid)){
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