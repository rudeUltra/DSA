class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min heap less goo
        priority_queue<int,vector<int>,greater<int>>pq;
        
        //maintain the k size heap siu
        for(int i=0;i<nums.size();++i){
            if(pq.size()<k){
                pq.push(nums[i]);
            }
            else{
                if(nums[i]>pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        
        return pq.top();
    }
};