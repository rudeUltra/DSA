class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Duplicates BoiIiIiII
        //and the OSCAR goes to Cilian Murphy..
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        
        
        for(int i=0;i<n-2;++i){
            if(i>0 && nums[i-1]==nums[i]){
                //same NO !
                continue;
            }
            int low=i+1;
            int high=n-1;
            int target=-nums[i];
            while(low<high){
                if(nums[low]+nums[high]==target){
                    //noICE
                    ans.push_back({nums[i],nums[low],nums[high]});
                    
                    //handle duplicates hm.
                    while(low<high && nums[low]==nums[low+1]){
                        low++;
                    }
                    while(low<high && nums[high]==nums[high-1]){
                        high--;
                    }
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high]>target){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        
        return ans;
    }
};