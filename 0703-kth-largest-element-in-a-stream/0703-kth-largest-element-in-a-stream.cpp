class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k1=0;
    KthLargest(int k, vector<int>& nums) {
        int n=nums.size();
        k1=k;
        for(int i=0;i<n;++i){
            if(pq.size()<k){
                pq.push(nums[i]);
            }
            else{
                if(k>pq.top()){
                    pq.pop(); //Boi Boi
                    pq.push(nums[i]); //Noice
                }
            }
        }
    }
    
    int add(int val) {
        //Control ur mind Its greedy 
        if(pq.size()<k1){
            pq.push(val);
            return pq.top();
        }
        if(val>pq.top()){
            pq.pop();
            pq.push(val); //Plz maintain K size xD professsional
        }
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */