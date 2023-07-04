
class Node{
  public:
   
    int val;
    int key;
    Node*prev;
    Node*next; //DOubly Linked List THey dont love they don love it 
     Node(int key1,int val1){
         key=key1;
         val=val1;
        prev=NULL;
        next=NULL;
    }
    
};



class LRUCache {
public:
    
    unordered_map<int,Node*>mp;
    Node *left,*right;
    
    //right signifies most recently used left means least recently used siu
    
    int cap;
    
    
    void remove(Node*curr){
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev; //sacrifice gg
        
    }
    
    void add(Node *curr){
        Node*nxt=right;
        Node*prv=right->prev;
        
        prv->next=curr;
        nxt->prev=curr;
        
        curr->next=nxt;
        curr->prev=prv;
    }
    
    LRUCache(int capacity) {
        cap=capacity; //COnstructor siuu
        left=new Node(0,0);
        right=new Node(0,0);
        left->next=right;
        right->prev=left;
    }
    
    int get(int key) {
        //2 cases check if key exists if it does move it to the most used siu
        if(mp.find(key)==mp.end()){
            return -1;
        }
        remove(mp[key]); //remove from current pos first then
        add(mp[key]); //move to most recently used
        
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        //one thing is certain this value will be added xD
        if(mp.find(key)!=mp.end()){
            remove(mp[key]);
        }
        mp[key]=new Node(key,value);
        add(mp[key]);
            
        if(mp.size()>cap){
            //stop the cap xD
            Node*lru=left->next;
            remove(lru); //least recently used siu
            mp.erase(lru->key);
          
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