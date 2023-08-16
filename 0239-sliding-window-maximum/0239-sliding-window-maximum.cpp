class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //basically a stack question but we need the front guy so we use a dequeue otherwise no need
        //brute force is to use a k sized heap but Tc will n log k
        //lets begin
        int n=nums.size();
        vector<int>ans;
        deque<int>pq;
        
        for(int i=0;i<n;++i){
            if(!pq.empty() && pq.front()+k<=i){
                pq.pop_front();
            }
            
            while(!pq.empty() && nums[pq.back()]<=nums[i]){
                pq.pop_back();
            }
            //USELESS mofos xD
             pq.push_back(i); //insert the current
        
            if(i>=k-1){
                ans.push_back(nums[pq.front()]);
            }
        }
        
        return ans;
        
    }
};