class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int>nextGreater(n,-1);
        
        stack<int>st;
        
        for(int i=0;i<n;++i){
            while(!st.empty() && nums2[st.top()]<nums2[i]){
                //who can i contribute to siu
                nextGreater[st.top()]=i;
                st.pop();
                
            }
            st.push(i); //use indexes not values
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;++i){
            mp[nums2[i]]=nextGreater[i];
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();++i){
            if(mp[nums1[i]]==-1){
                ans.push_back(-1);
            }
            else{
                ans.push_back(nums2[mp[nums1[i]]]);
            }
        }
        
        return ans;
    }
};