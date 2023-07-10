class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>m1;
        while(1){
            int temp=0;
            while(n){
                temp=(n%10)*(n%10)+temp;
                n=n/10;
            }
            if(temp==1){
                return true;
            }
            if(m1[temp]!=0){
                return false;
            }
            m1[temp]++;
            //if it repeats then cycle so return false
            n=temp;
        }
        return false;
    }
};