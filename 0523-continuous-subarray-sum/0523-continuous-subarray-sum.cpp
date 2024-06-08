class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        /* => (sum_j - sum_i) % k = 0
 => sum_j % k - sum % k = 0
 => sum_j % k = sum_i % k    <Relation derived !!!>*/
        //BC what a derivation!
        
        unordered_map<int,int>mp;
        int sum=0; //prefix sum
        
        for(int i=0;i<nums.size();++i){
            sum=sum+nums[i];
            sum=sum%k;
            
            if(sum==0 && i){
                //length >2
                return true;
            }
            
            if(mp.find(sum)!=mp.end()){
                int x=mp[sum];
                if((i-mp[sum])>1){
                    return true;
                }
                
            }
            else{
                mp[sum]=i;
            }
        }
        
        return false;
        
    }
};