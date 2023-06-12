class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        //question is defined very fuckall but k just say consecutive but k
        
        int i=0;
        int n=nums.size();
        
        while(i<n){
            string temp=to_string(nums[i]);
            int j=i+1;
            
            while(j<n && nums[j]==nums[j-1]+1){
                j++;
            }
            if(j!=i+1){
                
               if(j==n){
                      temp+="->"+to_string(nums[n-1]);
               }
                else{
                       temp+="->"+to_string(nums[j-1]);
                }
                
         
            }
            ans.push_back(temp);
            
            i=j;
            
        }
        
        return ans;
    }
};