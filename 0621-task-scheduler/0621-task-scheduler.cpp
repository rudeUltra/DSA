// The question states that once you start a particular task say 'A' you need atleast k seconds to pick up another A right?
// Hence we can think of the problem as trying to make as many blocks as we can of size (k+1)
// // Now we need to do that greedily, i.e. by picking up tasks with higher freq than others. Hence we can use a priority queue to get k elements of max_freq right?
#define pb push_back

class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        
        //k is the wait time between 2 same tasks
        
        unordered_map<char,int> hash;
        for(int i = 0; i<tasks.size(); i++) hash[tasks[i]]++;
        
        priority_queue<int> pq; // max queue
        
        for(auto it : hash) pq.push(it.second);
        
        int timer = 0;
        
        while(!pq.empty()) {
            vector<int> temp;
            for(int i = 0; i<=k; i++) { // block of size (k+1)
                if(!pq.empty()) {
                    temp.pb(pq.top()); // pick frequently occuring tasks (greedy)
                    pq.pop();
                }
            }
            
            for(int i = 0; i<temp.size(); i++) {
                if(--temp[i] > 0) pq.push(temp[i]); 
                // (if tasks of the kind remain push them back in)
            }
            
            timer += pq.empty() ? temp.size() : k+1; // if queue is empty then we got no remaining tasks hence the current block size 
			// is temp.size() else we got a block of size k+1
        }
        return timer;
    }
};