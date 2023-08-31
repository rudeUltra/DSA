class Solution {
public:
    class Node{
    public:
    int flag=0;
    Node *links[26];
    string word1="";
    
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
        curr->word1=word;
    }
    
    string search(string word) {
        
        int n=word.size();
        Node*curr=root;
        for(int i=0;i<n;++i){
            if(curr->isPresent(word[i])==0){
               return "";
            }
            curr=curr->getLink(word[i]);
            if(curr->flag==1){
                return curr->word1; //Because smalles possible word
            }
        }
        if(curr->flag==1){
                return curr->word1; //Because smalles possible word
            }
        
        return "";
        
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

    string replaceWords(vector<string>& dictionary, string sentence) {
        //Basically Trie is used for searching Siu and Prefixes in optimal time.
        Trie *ds=new Trie();
        int n=dictionary.size();
        for(int i=0;i<n;++i){
            ds->insert(dictionary[i]);
        }
        
        //string stream lets go
        stringstream ss(sentence);
        string data;
        string ans;
        while(getline(ss,data,' ')){
            string temp=ds->search(data);
            
            if(temp==""){
                ans=ans+data+" ";
            }
            else{
                ans=ans+temp+" ";
            }
        }
        
        ans.pop_back();
        return ans;
        
        
    }
};