class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        int i1=0;
        int j=1;
        for(int i=0;i<n;++i){
            int sum=target-nums[i];
            if(mp.find(sum)!=mp.end()){
                //siu
                j=i;
                target=sum;
                break;
            }
            mp[nums[i]]++;
        }
        for(int i=0;i<n;++i){
            if(nums[i]==target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
        
        return ans;
    }
};