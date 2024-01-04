class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
      
        
        int steps=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;++i){
            mp[nums[i]]++;
        }
        
        for(auto it:mp){
            if(it.second<2){
                return -1;
            }
            
            
            int temp=(it.second+2)/3;
            steps=steps+temp;
//             if(it.second%3==0){
//                 steps+=it.second/3;
//                 continue;
//             }
//             int num=it.second;
//             while(num){
//                 if(num<3)

//             }
            
            
        }
        return steps;
        
        
    }
};