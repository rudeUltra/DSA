class Solution {
public:
    
    vector<vector<string>>ans;
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        f(0,s,temp);
        return ans;
    }
    
    void f(int index,string s,vector<string>&curr){
        if(index==s.size()){
            ans.push_back(curr);
            return;
        }
        
        for(int i=index;i<s.size();++i){
            if(ispal(index,i,s)){
                curr.push_back(s.substr(index,i-index+1));
                f(i+1,s,curr);
                curr.pop_back();
            }
        }
    }
    
    bool ispal(int left,int right,string s){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};