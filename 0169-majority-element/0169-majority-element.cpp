class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //i guess the cancelling out option
        int count=1;
        int ans=nums[0];
        
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=ans){
                count--;
            }
            else{
                count++;
            }
            if(count==0){
                //fok ok ure the new king now gg
                ans=nums[i];
                count=1;
            }
        }
        
        return ans;
    }
};