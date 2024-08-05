class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mp;
        int n=arr.size();
        
        for(int i=0;i<n;++i){
            mp[arr[i]]++;
        }
        
        //Map the vector of strings? hm nice alSo
        for(int i=0;i<n;++i){
            if(mp[arr[i]]==1){
                k--;
                if(k==0){
                    return arr[i];
                }
            }
        }
        return "";
    }
};