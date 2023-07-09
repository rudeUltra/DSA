class Solution {
public:
    int helper(int i,string s,unordered_set<string>&st){
        int result= 1e9;
        int n= s.size();
        if(i==s.size()) return 0;
        for(int j=i; j<n; j++){
            string curr= s.substr(i,j-i+1);
            if(st.find(curr)!=st.end()){
                result= min(result,1+helper(j+1,s,st));
            }
            
        }
        return result;
    }
    int minimumBeautifulSubstrings(string s) {
        int n= s.size();
         unordered_set<string> st{"11110100001001", "110000110101", "1001110001", "1111101", "11001", "101", "1"};
        int ans= helper(0,s,st);
        if(ans>15) return -1;
        return ans;
    
        
    }
};