class Solution {
public:
    long long mod=1e9+7;
    long long my_pow(long long x,long long y){
        if(y==0){
            return 1;
        }
        long long ans=my_pow(x,y/2);
        ans=ans*ans;
        ans%=mod;
        if(y%2){
            ans*=x;
        }
        ans%=mod;
        return ans;
    }
    int countGoodNumbers(long long n) {
        //i thought of basic solution bruh xD
        //for meth problems take out pen and paper bhai..
        long long odd_positions=n/2;
        long long even_positions=n/2+n%2;
        
        return(my_pow(5,even_positions)*my_pow(4,odd_positions))%mod;

        
    }
};