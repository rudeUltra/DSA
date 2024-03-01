class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        int count=0;
        
        for(int i=0;i<n;++i){
            if(s[i]=='1'){
                count++;
                s[i]='0'; //ConvRt!
            }
        }
        
        int i=0;
        count--;
        s[n-1]='1';
        while(i<n && count){
            s[i]='1';
            count--;
            i++;
        }
        
        
        
        
        return s;
    }
};