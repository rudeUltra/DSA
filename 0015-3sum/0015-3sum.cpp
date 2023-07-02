class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        //3 sum so less than n-1 siu
        
        for(int i=0;i<n-2;++i){
            //target is 0 siuu
            if(i>0 && nums[i]==nums[i-1]){
                continue; //avoid duplicates bc
            }
            //2 pointer to find sum siu
            int target=-nums[i];
            int left=i+1;
            int right=n-1;
            
            while(left<right){
                if(nums[left]+nums[right]==target){
                    //wooow 
                    //but duplicates betichod
                    ans.push_back({nums[i],nums[left],nums[right]});
                    while(left<n-1 && nums[left]==nums[left+1]){
                        left++;
                    }
                    while(right>0 && nums[right]==nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
                else if(nums[left]+nums[right]<target){
                    //chota sed
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        
        return ans;
    }
};