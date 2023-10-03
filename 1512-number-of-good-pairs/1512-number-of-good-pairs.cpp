class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        
        int ans=0;
        for(int i=0;i<n;++i){
            mp[nums[i]]++;
        }
        
        for(auto it:mp){
            if(it.second>1){
                 int temp=(it.second*(it.second-1))/2; //no of pairs for n
               
                ans+=temp; 
                
            }
           
        }
        
        return ans;
    }
};