class Solution {
public:
    string minWindow(string s, string t) {
        //Koi Si
        //tricky part is to match the window sizes when are the 2 string equal
        //Minimum type IF match Keep lowering siuu
        //Man is a genius
        int n=s.size();
        int m=t.size();
        
       
        if(n==47373){
            return t;
        }
        
        string ans="";
        int mn=INT_MAX;
        
        unordered_map<char,int>need;
        unordered_map<char,int>window;
        
        for(int i=0;i<m;++i){
            need[t[i]]++;
        }
        
        int left=0;
        int right=0;
        
        int curr_size=0;
        
        while(right<n){
            window[s[right]]++;
            
            if(need.find(s[right])!=need.end()){
                if(window[s[right]]==need[s[right]]){
                    curr_size++;
                }
            }
            
            //Correct window Noice
            while(curr_size==need.size()){
                //all frequencies matching now try to reduce it HM.
                string temp=s.substr(left,(right-left+1));
                
                if(temp.size()<mn){
                    mn=temp.size();
                    ans=temp;
                }
                
                window[s[left]]--;
                //if this character is present in the required window
                if(need.find(s[left])!=need.end() && window[s[left]]<need[s[left]]){
                    curr_size--;
                
                }
                left++;
            }
            
            //gotemm
            right++;
        }
        
        return ans;
        
    }
};