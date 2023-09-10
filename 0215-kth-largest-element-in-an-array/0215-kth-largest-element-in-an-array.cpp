class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Let's first do it using heap then quicksort hm quickselect more challenging xD
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=nums.size();
        //Maintain the k size siu
        for(int i=0;i<n;++i){
            pq.push(nums[i]);
            if(pq.size()>k){
                //Kick the smalles siu
                pq.pop();
            }
        }
        return pq.top();
    }
};