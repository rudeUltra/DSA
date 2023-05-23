class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int size1;
    KthLargest(int k, vector<int>& nums) {
        size1=k;
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(i<k){
                pq.push(nums[i]);
            }
            else{
                if(nums[i]>pq.top()){
                    pq.pop();
                    pq.push(nums[i]); //maintain the size siu
                }
            }
        }
    }
    
    int add(int val) {
        
        if(pq.empty() || pq.size()<size1){
            pq.push(val);
            return pq.top();
        }
        
        
        if(val<pq.top()){
            return pq.top(); //guaranteed always k will be there
        }
        else{
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */