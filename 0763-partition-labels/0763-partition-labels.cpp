class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        for(int i = 0; i < n; i++){
            mpp[s[i]] = i;
        }
        int maxi = 0, prev = -1;
        vector<int>ans;
        for(int i = 0; i < n; i++){
            maxi = max(maxi,mpp[s[i]]);     // updating maxi if current element's last occurence is greater than maxi
            if(maxi == i){                          // since maxi == i it means last occurence of all elements till now is present in this partition so we add this partition to the vector.
                ans.push_back(maxi - prev);
                maxi = -1;
                prev = i;
            }
        }
        return ans;
    }
};