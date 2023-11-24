class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //not a hashmap problem siu
        int n=nums.size();
        
        vector<vector<int>>ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;++i){
            //I is fixed now find the rest with two pointer approach siu
            if(i>0 && nums[i]==nums[i-1]){
                continue; //Duplicate
            }
            
            int left=i+1;
            int right=n-1;
            
            int target=-nums[i];
            
            while(left<right){
                int sum=nums[left]+nums[right];
                
                if(sum<target){
                    left++;
                }
                else if(sum>target){
                    right--;
                }
                else{
                    //gotemm
                    ans.push_back({nums[i],nums[left],nums[right]});
                    
                    //now take care of duplicates 
                    
                    while(left<n-1 && nums[left]==nums[left+1]){
                        left++;
                    }
                    while(right>0 && nums[right]==nums[right-1]){
                        right--;
                    }
                    right--;
                    left++;
                }
            }
            
           
        }
         return ans;
    }
};