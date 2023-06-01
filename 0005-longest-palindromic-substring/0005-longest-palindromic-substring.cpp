class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=0){
            return "";
        }
        if(n==1){
            return s;
        }
        int start=0;
        int end=0;
        int l=0,r=0;
        for(int i=0;i<n;++i){
            //two conditions even palindrome and odd palindrome
            l=i;
            r=i+1;
            
            //odd case normal
            while(l>=0 && r<n && s[l]==s[r]){
                //check for new max lenght 
                if(r-l>end-start){
                    start=l;
                    end=r;
                }
                l--;
                r++;
            }
            
            //even case a-c-a
            
            l=i;
            r=i+2; //ignore middle guy
              while(l>=0 && r<n && s[l]==s[r]){
                //check for new max lenght 
                if(r-l>end-start){
                    start=l;
                    end=r;
                }
                l--;
                r++;
            }
            
        }
        string temp;
        for(int i=start;i<=end;++i){
            temp.push_back(s[i]);
        }
        return temp; //less go
    }
};