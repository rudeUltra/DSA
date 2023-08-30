unordered_map<string,int>mp;

class MapSum {
public:
     
    
class Node{
    public:
    int flag=0;
    Node *links[26];
    int count=0;
    Node(){
        for(int i=0;i<26;++i){
            links[i]=NULL;
        }
    }
    int isPresent(char x){
        if(links[x-'a']==NULL){
            return 0;
        }
        return 1; //link is there
    }
    
    Node* getLink(char x){
        return links[x-'a'];
    }
    void setLink(char x,Node *temp){
        links[x-'a']=temp;
    }
    
};

class Trie {
public:
    
    Node*root;
    Trie() {
        root=new Node();
    }
    
    void insert1(string word,int x) {
        int n=word.size();
        Node*curr=root;
        for(int i=0;i<n;++i){
            if(curr->isPresent(word[i])==0){
                Node *temp=new Node();
                curr->setLink(word[i],temp);
            }
            curr=curr->getLink(word[i]);
            curr->count+=x;
        }
        curr->flag=1; //Indicating that a word is ending here siu
    }
    
     void insert2(string word,int x,int prev) {
        int n=word.size();
        Node*curr=root;
        for(int i=0;i<n;++i){
            if(curr->isPresent(word[i])==0){
                Node *temp=new Node();
                curr->setLink(word[i],temp);
            }
            curr=curr->getLink(word[i]);
            curr->count=(curr->count-prev)+x;
        }
        curr->flag=1; //Indicating that a word is ending here siu
    }
    
    
    int search(string word) {
        
        int n=word.size();
        Node*curr=root;
        int sum=0;
        for(int i=0;i<n;++i){
            if(curr->isPresent(word[i])==0){
               return sum;
            }
            curr=curr->getLink(word[i]);
            
        }
        
        return sum=curr->count;
        
    }
    
    bool startsWith(string prefix) {
        
        
         int n=prefix.size();
        Node*curr=root;
        for(int i=0;i<n;++i){
            if(curr->isPresent(prefix[i])==0){
               return false;
            }
            curr=curr->getLink(prefix[i]);
        }
        //Ab aa hi gaye hai to xD
        return true;
        
    }
};
    
    Trie*ds;
   unordered_map<string,int>mp;

    MapSum() {
        ds=new Trie();
    }
    
    void insert(string key, int val) {
        if(mp[key]!=0){
            //new val hm
            int prev=mp[key];
            ds->insert2(key,val,prev);
        }
        else{
            ds->insert1(key,val);
        }
        
        mp[key]=val;
    }
    
    int sum(string prefix) {
        return ds->search(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */