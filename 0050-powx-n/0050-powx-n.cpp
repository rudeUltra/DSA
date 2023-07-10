class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n<0) return 1/x*(1 / (myPow(x,abs(n)-1)));
        if(n == 0)return 1;
        if(n == 2)return x*x;
        if(n%2==0)return myPow(x*x,n/2);
        return x * myPow(x,n-1);
    }
};