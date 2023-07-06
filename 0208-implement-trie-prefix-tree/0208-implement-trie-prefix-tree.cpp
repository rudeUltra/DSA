
class Node{
  public:
    Node *links[26];
    int flag; //to mark the end of the word siu
    
    Node(){
        flag=0;
        for(int i=0;i<26;++i){
            links[i]=NULL;
        }
    }
    
    bool isset(char x){
        int temp=x-'a';
        if(links[temp]==NULL){
            return false;
        }
        return true;
    }
    void create(char a,Node*temp){
        links[a-'a']=temp;
    }
    Node* next(char a){
        return links[a-'a'];
    }
    
    
};



class Trie {
public:
    
    Node *root;
    
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node*curr=root;
        for(int i=0;i<word.size();++i){
            if(curr->isset(word[i])==0){
                //create a new link
                Node*temp=new Node();
                curr->create(word[i],temp);
            }
            curr=curr->next(word[i]);
        }
        curr->flag=1;
    }
    
    bool search(string word) {
        Node *curr=root;
        for(int i=0;i<word.size();++i){
            if(curr->isset(word[i])==0){
                return false;
            }
            curr=curr->next(word[i]);
        }
        if(curr->flag==1){
            return true;
        }
        return false;
        
    }
    
    bool startsWith(string prefix) {
        Node *curr=root;
        for(int i=0;i<prefix.size();++i){
            if(curr->isset(prefix[i])==0){
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