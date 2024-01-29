class Node{
    public:
    
    Node*links[2];
    
    Node(){
        links[0]=NULL;
        links[1]=NULL;
    }
    
    bool bitSet(int bit){
        if(links[bit]==NULL){
            return false;
        }
        return true;
    }
    
    void addBit(int bit){
        Node *temp=new Node();
        links[bit]=temp;
    }
    
    Node*next(int bit){
        return links[bit];
    }
};



class Trie{
    public:
    
    Node* root;
    
    Trie(){
        root=new Node();
    }
    
    void push(int num){
        Node*curr=root; //POINT TO THE root hm
        
        for(int i=31;i>=0;--i){
            int bit=(num>>i)&1;
            if(curr->bitSet(bit)==false){
                curr->addBit(bit);
            }
            curr=curr->next(bit);
        }
        //added hm
    }
    
    int getMax(int num){
        Node*curr=root;
        
        int ans=0;
        
        for(int i=31;i>=0;--i){
            int bit=(num>>i)&1;
            
            //check if opposite bit possible or not siu
            if(curr->bitSet(!bit)==true){
                //gotemm
                ans=ans | (1<<i);
                curr=curr->next(!bit); //track the trie hm.
            }
            else{
                curr=curr->next(bit);
            }
            
        }
        
        return ans;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        //It's doing Nx32 hm noice
        int n=nums.size();
        
        Trie* root=new Trie();
        
        for(int i=0;i<n;++i){
            root->push(nums[i]);
        }
        
        int ans=0;
        
        for(int i=0;i<n;++i){
            ans=max(ans,root->getMax(nums[i]));
        }
        
        return ans;
    }
};