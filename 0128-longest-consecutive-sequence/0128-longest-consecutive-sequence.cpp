class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=1;
        int n=nums.size();
        for(int i=0;i<n;++i){
            mp[nums[i]]++;
            
        }
        if(n==0){
            return 0;
        }
        for(int i=0;i<n;++i){
            
            if(mp[nums[i]]==0){
                continue; //jeje
            }
            
            if(mp[nums[i]-1]!=0){
                continue; //prev will take care siu
            }
            else{
                //fuck lets start counting
                int temp=1;
                int next=nums[i]+1;
                while(mp[next]!=0){
                    mp[next]--;
                    temp++;
                    next++;
                }
                ans=max(ans,temp);
            }
        }
        
        return ans;
        
    }
};