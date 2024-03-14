class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //No of subarrays SO! prefix sum would be better i guess
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        int count=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            cout<<sum<<" ";
            
            if(sum==goal){
                //gOTemm
                count++;
            }
            
            if(mp.find(sum-goal)!=mp.end()){
                //exists hm.
                count+=mp[sum-goal];
            }
            mp[sum]++;
        }
        
        return count;
    }
};