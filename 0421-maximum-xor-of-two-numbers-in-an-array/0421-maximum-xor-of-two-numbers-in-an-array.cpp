struct Node{
    Node *links[2]; //0 and 1 siu

    Node * get(int c){
        return links[c];
    }
    bool isSet(int c){
        if(links[c]==NULL){
            return false;
        }
        return true;
    }
    void set(int c,Node* node){
        links[c]=node;
    }
};
class Trie{
    public:
    Node *root;
    Trie(){
        root=new Node(); //sIUUU
    }
    void insert(int num){
        Node *curr=root;
        for(int i=31;i>=0;--i){
            int set=(num>>i)&1;
            //Right shift because we only want 1 no more Big brain
            
            if(!curr->isSet(set)){
                curr->set(set,new Node());
            }
            curr=curr->get(set);
        }
    }
    int getmax(int num){
        //just like searching SIUu
        Node *curr=root;
        int ans=0;
        for(int i=31;i>=0;--i){
            int set=(num>>i)&1;
            //there will always be a reference node since 31 numbers bruh
            // if opposite exists then add it and move on 
            if(curr->isSet(!set)){
                //siuu
                ans=ans | (1<<i); //building the ans; Left shift here because we want to add the number bruh
                curr=curr->get(!set);
            }
            else{
                curr=curr->get(set);
            }
        }
        return ans;
    }
};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        //sai raam sighs
        int n=nums.size();
        vector<int>temp=nums;
        Trie t;
        int mx=INT_MIN;
        for(int i=0;i<n;++i){
            t.insert(nums[i]);
        }
        for(int i=0;i<n;++i){
            mx=max(mx,t.getmax(temp[i]));
        }

        return mx;

    }
};