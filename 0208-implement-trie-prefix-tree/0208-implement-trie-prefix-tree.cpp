class Node{
    public:
    bool end;
    Node* links[26]; //26 characters siu
    
    
    Node(){
        for(int i=0;i<26;++i){
            links[i]=NULL;
        }
        end=false;
    }
    
    bool linkExists(char a){
        if(links[a-'a']==NULL){
            return false;
        }
        return true;
    }
    
    Node* link(char a){
        return links[a-'a'];
    }
    
    void addLink(char a){
        Node*temp=new Node();
        links[a-'a']=temp;
    }
      
};


class Trie {
public:
    
    Node*root;
    Trie() {
        root=new Node(); //aha root node gotemm
    }
    
    void insert(string word) {
        int n=word.size();
        
        Node*root1=root; //point to the root hm
        
        for(int i=0;i<n;++i){
            if(root1->linkExists(word[i])==false){
                //sed no link
                root1->addLink(word[i]);
            }
            //next
            root1=root1->link(word[i]);
        }
        
        //aha
        
        root1->end=true; //word ends here
        
    }
    
    bool search(string word) {
        
        int n=word.size();
        Node*root1=root; //point to the root hm
        
        for(int i=0;i<n;++i){
            if(root1->linkExists(word[i])==false){
                //sed no link
                return false;
            }
            //next
            root1=root1->link(word[i]);
        }
        
        //aha
        
        return root1->end;
        
    }
    
    bool startsWith(string prefix) {
        
        int n=prefix.size();
        Node*root1=root; //point to the root hm
        
        for(int i=0;i<n;++i){
            if(root1->linkExists(prefix[i])==false){
                //sed no link
                return false;
            }
            //next
            root1=root1->link(prefix[i]);
        }
        
        //aha
        
        return true; //kUch to hoga Xd
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */