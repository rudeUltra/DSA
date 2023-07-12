class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        vector<int>lps(m,0);
        int prevlps=0;
        int i=1;
        
        while(i<m){
            if(needle[i]==needle[prevlps]){
                lps[i]=1+prevlps;
                prevlps++;
                i++;
            }
            else if(prevlps==0){
                lps[i]=0;
                i++;
            }
            else{
                prevlps=lps[prevlps-1];
            }
        }
        
        i=0;
        int j=0;
        
        while(i<n){
            if(haystack[i]==needle[j]){
                ++i;
                ++j;
            }
            
            else{
                if(j==0){
                    ++i;
                }
                else{
                    j=lps[j-1];
                }
            }
            
            
            if(j==m){
                return i-m;
            }
        }
        
        return -1;
        
    }
};