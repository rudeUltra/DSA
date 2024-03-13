/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    
    
    Node* cloneGraph(Node* node) {
        //dO Normal BFS I guess HM. Noice
        unordered_map<Node*,Node*>mp;
        queue<Node*>pq;
        if(node==NULL){
            return node;
        }
        pq.push(node);
        unordered_map<Node*,int>visited;
        visited[node]=1;
        mp[node]=new Node(node->val);
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            
            for(auto neighbor:it->neighbors){
                if(mp.find(neighbor)==mp.end()){
                    //Create One noICE
                    mp[neighbor]=new Node(neighbor->val);
                }
                mp[it]->neighbors.push_back(mp[neighbor]);
                if(visited[neighbor]!=1){
                    //Noice
                    visited[neighbor]=1;
                    pq.push(neighbor);
                }
            }
            
        }
        
        return mp[node];
    }
};