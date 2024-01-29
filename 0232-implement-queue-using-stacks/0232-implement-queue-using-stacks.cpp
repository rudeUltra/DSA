class MyQueue {
public:
    
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        //Amorotized
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.size()!=0){
            int ans=st2.top();
            st2.pop();
            return ans;
        }
        
        //sed
        
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        
        int ans=st2.top();
        st2.pop();
        return ans;
    }
    
    int peek() {
        
         if(st2.size()!=0){
            int ans=st2.top();
            return ans;
        }
        
        //sed
        
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        
        int ans=st2.top();
        return ans;
        
    }
    
    bool empty() {
        if(st1.size()==0 && st2.size()==0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */