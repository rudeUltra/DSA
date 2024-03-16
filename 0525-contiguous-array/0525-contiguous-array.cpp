class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //cutting 0 cuts 1 so sum becomes 0 ooH noice intuition
        unordered_map<int,int>mp;
        mp[0]=-1; //index VEry important
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==1){
                sum=sum+1;
            }
            else{
                sum=sum-1; //0
            }
            
            if(mp.find(sum)!=mp.end()){
                //possible answer
                if(i-mp[sum]>ans){
                    ans=i-mp[sum];
                }
                
            }
            else{
                mp[sum]=i;
            }
            
            
        }
        return ans;
    }
};