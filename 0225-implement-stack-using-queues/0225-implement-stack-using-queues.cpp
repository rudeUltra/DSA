class MyStack {
public:
    
    queue<int>pq1;
    MyStack() {
        //I say we only use 1 queue hm
    }
    
    void push(int x) {
        pq1.push(x);
    }
    
    int pop() {
        int n=pq1.size();
        while(n>1){
            int temp=pq1.front();
            pq1.pop();
            pq1.push(temp);
            n--;
        }
        //Queue is FIFO
        int ans=pq1.front();
        pq1.pop();
        return ans;
        
    }
    
    int top() {
        
        int n=pq1.size();
        while(n>1){
            int temp=pq1.front();
            pq1.pop();
            pq1.push(temp);
            n--;
        }
        //Queue is FIFO
        int ans=pq1.front();
        pq1.pop();
        pq1.push(ans);
        return ans;
        
        
    }
    
    bool empty() {
        return pq1.size()==0;
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */