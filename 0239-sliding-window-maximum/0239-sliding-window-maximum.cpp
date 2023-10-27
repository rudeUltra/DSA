class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        deque<int>pq;
        
        for(int i=0;i<n;++i){
            if(pq.size()!=0 && pq.front()<=(i-k)){
                pq.pop_front();
            }
            
            while(!pq.empty() && nums[pq.back()]<nums[i]){
                pq.pop_back();
            }
            pq.push_back(i);
            
            if(i>=k-1){
                ans.push_back(nums[pq.front()]);
            }
        }
        
        return ans;
    }
};