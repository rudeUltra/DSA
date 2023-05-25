class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        unordered_map<int,int>m1;
        int sum=0;
        int i=0;
        int count=0;
        while(i<n){
            sum=sum+nums[i];
            cout<<sum<<" ";
            
            if(sum==k){
                count++;
            }
            if(m1.find(sum-k)!=m1.end()){
                count+=m1[sum-k];
            }
            m1[sum]+=1;
            i+=1;
            
        }
        return count;
    }
};