class Node{
    
    public:
    int key;
    int val;
    Node *prev;
    Node *next;
    
    Node(){
        prev=NULL;
        next=NULL;
    }
    
    Node(int key1,int val1){
        prev=NULL;
        next=NULL;
        key=key1;
        val=val1;
    }
    
};



class LRUCache {
public:
    Node*left=new Node();
    Node*right=new Node();
    int cap=0;
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        left->next=right;
        right->prev=left;
    }
    
    
    
    
    
    void remove(Node *curr){
        //from curr position
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }
    
    void add(Node *curr){
        //always to the right
        Node*right1=right;
        Node *prev1=right->prev;
        
        curr->next=right1;
        curr->prev=prev1;
        
        prev1->next=curr;
        right->prev=curr;
        
    }
    
    
    int get(int key) {
        //check map hm
        if(mp.find(key)==mp.end()){
            return -1;
        }
        int ans=mp[key]->val;
        remove(mp[key]);
        add(mp[key]); //most recently used
        
        return ans;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            
            remove(mp[key]);
            mp[key]->val=value;
        }
        else{
           mp[key]=new Node(key,value);
        }
        
        add(mp[key]);
            
        if(mp.size()>cap){
            //stop the cap xD
            Node*lru=left->next;
            remove(lru); //least recently used siu
            mp.erase(lru->key); //to reduce the size of the map we need the key valUE HmmM
          
        }
        // cout<<cap<<" ";
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */