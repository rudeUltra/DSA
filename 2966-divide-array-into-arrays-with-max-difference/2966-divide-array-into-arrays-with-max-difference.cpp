class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        //Me Gustas tu
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i=i+3){
            int j=i;
            vector<int>temp;
            while(j<i+3){
                temp.push_back(nums[j]);
                j++;
            }
            
            //check temp
            if((temp[1]-temp[0])>k || (temp[2]-temp[1])>k || temp[2]-temp[0]>k){
                return {};
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};