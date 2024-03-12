class Node{
    public:
    Node*links[26];
    bool flag=false;
    
    Node(){
        for(int i=0;i<26;++i){
            links[i]=NULL;
        }
    }
    
    bool linkExists(char word){
        if(links[word-'a']!=NULL){
            return true;
        }
        return false;
    }
    
    void createLink(char word){
        Node*temp=new Node();
        links[word-'a']=temp;
        return;
    }
    
    Node * next(char word){
        return links[word-'a'];
    }
    
};
class Trie {
public:
    Node*root;
    Trie() {
        root=new Node(); 
        //Initialization Boi.
    }
    
    void insert(string word) {
        int n=word.size();
        Node*curr=root; //like linked List nOice
        for(int i=0;i<n;++i){
            if(!curr->linkExists(word[i])){
                curr->createLink(word[i]);
            }
            curr=curr->next(word[i]);
        }
        curr->flag=true; //word Exists NOice
        //Striver used function because he kept the data as private NOice
    }
    
    bool search(string word) {
        
        int n=word.size();
        Node*curr=root; //like linked List nOice
        for(int i=0;i<n;++i){
            if(!curr->linkExists(word[i])){
                return false;
            }
            curr=curr->next(word[i]);
        }
        if(curr->flag==true){
            return true;
        }
        return false;
        
    }
    
    bool startsWith(string prefix) {
        int n=prefix.size();
        Node*curr=root; //like linked List nOice
        for(int i=0;i<n;++i){
            if(!curr->linkExists(prefix[i])){
                return false;
            }
            curr=curr->next(prefix[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */