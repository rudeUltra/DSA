class Solution {
public:
    bool isvalid(int mid,vector<int>&nums,int k){
        //largest can be upto mid if more than mid then return false
        //should also satisfy k so
        int count=1;
        
        int sum=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>mid){
                return false;
            }
            sum+=nums[i];
            if(sum>mid){
                count++;
                sum=nums[i];
            }
        }
        if(count<=k){
            return true;
        }
        return false;
    }
    
    
    int splitArray(vector<int>& nums, int k) {
        //same question as allocation of books continuos subarray remmeber very important
        ///minimize the max type siu
        
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
        }
        int low=1;
        int high=sum;
        int ans=0;
        
        while(low<=high){
            int mid=(low+high)/2; //integer overflow siu
            cout<<mid<<" ";
            
            if(isvalid(mid,nums,k)){
                ans=mid;
                high=mid-1; //minimze find an even smaller number siu
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};