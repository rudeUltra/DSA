class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        
        int count=0;
        vector<vector<int>>ans;
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;++i){
            mp[nums[i]]++;
        }
        
        while(count<n){
            //Till all the elements are filled siu
            vector<int>temp;
            
            for(auto it:mp){
                if(it.second!=0){
                    temp.push_back(it.first);
                    mp[it.first]--;
                    count++;
                }
               
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};