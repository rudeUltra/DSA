class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //lets go xD
        deque<int>dq;
        int n=nums.size();
        vector<int>ans;

        for(int i=0;i<n;++i){
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }

            //hello motherfucker xD delete all thhe elements which are lesser than i cuz they can never be the ans
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }

            //only delete smaller then push even if we see next element or current in i++ being smaller than dequeue top we still push it because it can also be the ans in the future we dont know the top guy can get popped later if it is out of range

            dq.push_back(i); 
        

        if(i>=k-1){
            //proper size ahem so store the ans
            ans.push_back(nums[dq.front()]); //front because we guarantee that the max will be here if another max was there it would have popped everyone then be in the front siuuu
        }
        }
        return ans;
    }
};