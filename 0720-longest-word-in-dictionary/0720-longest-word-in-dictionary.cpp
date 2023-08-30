


class Solution {
    public:
    
    class Node{
    public:
    int flag=0;
    Node *links[26];
    
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
    
    void insert(string word) {
        int n=word.size();
        Node*curr=root;
        for(int i=0;i<n;++i){
            if(curr->isPresent(word[i])==0){
                Node *temp=new Node();
                curr->setLink(word[i],temp);
            }
            curr=curr->getLink(word[i]);
        }
        curr->flag=1; //Indicating that a word is ending here siu
     
    }
    
    bool search(string word) {
        
        int n=word.size();
        Node*curr=root;
        for(int i=0;i<n;++i){
            if(curr->isPresent(word[i])==0){
               return false;
            }
            curr=curr->getLink(word[i]);
            if(curr->flag==0){
                return false;
            }
        }
        if(curr->flag==1){
            return true;
        }
        return false;
        
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


    
    string longestWord(vector<string>& words) {
        //No need to generate all substrings and compare we can just modify the Search function of the Trie siu
        int n=words.size();
        Trie *ds=new Trie();
        
        for(int i=0;i<n;++i){
            ds->insert(words[i]);
        }
        
        string ans="";
        sort(words.begin(),words.end());
        
        for(int i=0;i<n;++i){
            
            string temp=words[i];
            temp.pop_back();
            
            if(ds->search(temp) && ans.size()<words[i].size()){
                ans=words[i];
            }
        }
        if(ans.size()==0 && words[0].size()==1){
            ans=words[0];
        }
        
        return ans;
        
       
    }
};