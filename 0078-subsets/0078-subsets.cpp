class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        for(int num=0;num<(1<<n);++num){
            //0 1 2 3 4 5 etc
            vector<int>temp;
            for(int i=0;i<n;++i){
                if(num&(1<<i)){
                    //i'th bit is set siu
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};