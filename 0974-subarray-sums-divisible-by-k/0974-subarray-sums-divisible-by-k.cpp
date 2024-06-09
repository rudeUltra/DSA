class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>m1;
        int n=nums.size();
        int sum=0;
        int rem=0;
        int ans=0;
        for(int i=0;i<n;++i){
            sum=sum+nums[i]; //formula s1(x)=kn+x s2(x)=km+x s2-s1=k(m-n)+x-x=k(n-m) which is a multiple of k wtf meths
            rem=sum%k;
            if(rem<0){
                rem=rem+k; //convert negative remainder to positive
            }
            if(rem==0){
                ans++; //for single digit
            }
            if(m1.find(rem)!=m1.end()){
                ans=ans+m1[rem];
                m1[rem]++; //remainder exists in the map so increase the count
            }
            else{
                m1[rem]++;
            }
        }
        return ans;
    }
};