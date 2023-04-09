class Solution {
public:
    bool isprime(int n){
        bool is_prime=true;
          if(n==0||n==1){
            is_prime=false;
          }
          // loop to check if n is prime
          for(int i=2;i<=n/2;++i){
            if(n%i==0){
              is_prime=false;
              break;
            }
          }
        return is_prime;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size(),maxi=0;
        for(int i=0;i<n;i++){//check isprime if it is strictly greater than maxi
            if(nums[i][i]>maxi && isprime(nums[i][i]))
                maxi=max(maxi,nums[i][i]);
            if(nums[i][n-i-1]>maxi && isprime(nums[i][n-i-1]))
                maxi=max(maxi,nums[i][n-i-1]);
        }
        return maxi;
    }
};