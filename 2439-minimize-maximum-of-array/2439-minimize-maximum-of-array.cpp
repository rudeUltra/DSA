class Solution {
public:
    
    bool ispossible(vector<long long>nums,long long d)
    {
        int n=nums.size();
        if(nums[0]>d)
            return false;
        for(int i=1;i<n;i++)
        {  
            
            long long x=d-nums[i-1];
            if(i==2 && d==5){
                cout<<x<<" ";
            }
            if(nums[i]>d)
            {
                if(nums[i]-d>x)
                    return false;
            }
            nums[i-1]+=x;
            nums[i]-=x;
            
        }
        if(d==5){
            for(auto it:nums){
                cout<<it<<" ";
            }
        }
        return true;
    }
    
    int minimizeArrayValue(vector<int>& arr) {
        int n=arr.size();
        vector<long long>nums;
        for(auto it:arr)
        {
            nums.push_back(it);
        }
        int s=0;
        int e=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(s<=e)
        {
            long long d=(s+e)/2;
            if(ispossible(nums,d))
            {
                ans=d;
                e=d-1;
            }
            else{
                s=d+1;
            }
        }
        return ans;
        
    }
};