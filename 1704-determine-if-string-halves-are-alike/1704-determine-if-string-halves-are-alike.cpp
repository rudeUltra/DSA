class Solution {
public:
    
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
         if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            return true;
        }
        
        return false;
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        int total_count=0;
        int counta=0;
        
        for(int i=0;i<n;++i){
            if(isVowel(s[i])){
                total_count++;
            }
        }
        
        for(int i=0;i<n/2;++i){
            if(isVowel(s[i])){
                counta++;
            }
        }
        
        if(counta==(total_count-counta)){
            return true;
        }
        
        return false;
    }
};