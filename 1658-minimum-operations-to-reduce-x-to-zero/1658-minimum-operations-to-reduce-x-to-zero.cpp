class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //big brain solution bc!
        //big brain sliding window bc
        //Basically question is that find the max subarray of sum = total-x Noice
        
        int n=nums.size();
       
        int ans=INT_MAX;
        int total=0;
        for(int i=0;i<n;++i){
            total+=nums[i];
        }
        int required=total-x;
         if(n==2){
            if(required<0){
                return -1;
            }
             if(required==0){
                 return 2;
             }
             return 1;
        }
        int left=0;
        int right=0;
        long long sum=0;
        //SLiding window siu
        while(right<nums.size()){
            sum+=nums[right];
          
            
            while(sum>required && left<=right){

                sum=sum-nums[left];
                left++;
            }
            if(sum==required){
        
                    int curr=(right-left+1);
                    ans=min(ans,n-curr);
                }
            right++;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
        
    }
};