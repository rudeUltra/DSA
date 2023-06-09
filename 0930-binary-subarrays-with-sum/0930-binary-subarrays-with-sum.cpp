class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //same concept bc siuuU prefix sum
        unordered_map<int,int>mp;
        int sum=0;
        int n=nums.size();
        int count=0;

        for(int i=0;i<n;++i){
            sum=sum+nums[i];

            if(sum==goal){
                count++;
            }
            if(mp.find(sum-goal)!=mp.end()){
                count+=mp[sum-goal];
            }
            mp[sum]++;
        }
        return count;

    }
};