class Solution {
public:
    
    void palindrome(string &s,int l,int r,int &left,int &right,int &mx){
        int n=s.size();
        
        while(l>=0 && r<n){
            if(s[l]!=s[r]){
                break;
            }
            if((r-l+1>mx)){
                mx=r-l+1;
                left=l;
                right=r;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        //Siuu
        int n=s.size();
        string ans="";
        int left=0;
        int right=0;
        int mx=INT_MIN;
        for(int i=0;i<n;++i){
            palindrome(s,i,i+1,left,right,mx);
            palindrome(s,i,i,left,right,mx);
            
        }
        
        ans=s.substr(left,right-left+1);
        
        return ans;
    }
};