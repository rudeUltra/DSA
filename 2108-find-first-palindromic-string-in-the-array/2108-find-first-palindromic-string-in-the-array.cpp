class Solution {
public:
    
    bool isPalindrome(string &curr){
        int n=curr.size();
        int i=0;
        int j=n-1;
        
        while(i<j){
            if(curr[i]!=curr[j]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        
        for(int i=0;i<n;++i){
            if(isPalindrome(words[i])){
                return words[i];
            }
        }
        
        return "";
    }
};