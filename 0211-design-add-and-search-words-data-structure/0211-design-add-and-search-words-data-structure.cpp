class TrieNode{
    public:
    TrieNode *links[26];
    bool flag = false;
    bool hasKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, TrieNode *node){
        links[ch - 'a'] = node;
    }
    TrieNode *get(char ch){
        return links[ch - 'a'];
    }
    void flagSwitch(){
        flag=true;
    }
    bool isEnd(){
        return flag == true;
    }
};

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *node  = root;
        for(int i=0;i<word.length();i++){
            if(!node->hasKey(word[i])){
                node->put(word[i],new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->flagSwitch();
    }
    bool helper(string word, TrieNode *node){
        for(int i=0;i<word.length();i++){
            if(word[i]=='.'){
				/*
					This piece of code is the key to solve this problem 
					so what this line basically do is it checks if our string has any possibilty 
					for any character between a to z where we get our desired results. 
					So we just make a recursive call to the same function for 
					every possible character at the place of "."!
				*/
                for(char ch='a';ch<='z';ch++){
                    if(node->hasKey(ch) && helper(word.substr(i+1),node->get(ch))) 
                        return true; //try all combinations a-z siu when dot comes
                }
                return false;
            }
            else{
            if(!node->hasKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
            }
        }
        if(node->isEnd()) {
            return true; 
        }
        return false;     
    }
    
    bool search(string word) {
        TrieNode *node  = root;
        return helper(word,node);
    }
};