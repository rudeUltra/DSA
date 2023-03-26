class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> m;
        int j,k=0;
        for(int i=0;i<n;++i){
            int sum=target-nums[i];
            if(m[sum]==1){
                j=i;
                break;
            }
            m[nums[i]]++;
        }
        int left=target-nums[j];
        for(int i=0;i<n;++i){
            if(nums[i]==left){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
        return ans;
    }
};