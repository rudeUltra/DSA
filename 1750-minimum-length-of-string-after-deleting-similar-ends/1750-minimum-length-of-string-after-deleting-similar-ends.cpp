class Solution {
public:
    
   
    
    int minimumLength(string s) {
        int n=s.size();
        int left=0;
        int right=n-1;
        
        while(left<right){
            if(s[left]!=s[right]){
                
                return (right-left)+1;
            }
            else{
                char temp='a';
                if(s[left]=='b'){
                    temp='b';
                }
                if(s[right]=='c'){
                    temp='c';
                }
                
                while(left<=right && s[left]==temp){
                    left++;
                }
                while(left<=right && s[right]==temp){
                    right--;
                }
            }
        }
        cout<<left<<" "<<right;
        if(left>right){
            return 0;
        }
        return (right-left+1);
    }
};