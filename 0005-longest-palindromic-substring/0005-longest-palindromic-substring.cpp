class Solution {
public:
    int mx=1;
    void palindrome(string s,int i,int j,int &left,int &right){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            if(j-i+1>mx){
                mx=j-i+1;
                left=i;
                right=j;
                
            }
            --i;
            j++;
        }
    }
    
    
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        int left=0;
        int right=0;
        
        
        for(int i=0;i<n;++i){
            //odd case
            palindrome(s,i,i,left,right);
            palindrome(s,i,i+1,left,right);
        }
        
        ans=s.substr(left,mx);
        
        return ans;
        
        
        
    }
};