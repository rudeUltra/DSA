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
        //BFs solution makes more sense here siu
        
        unordered_map<Node*,Node*>visited;
        
        if(node==NULL){
            return NULL; //siu
        }
        
        visited[node]=new Node(node->val);
        
        queue<Node*>pq;
        pq.push(node);
        
        while(!pq.empty()){
            Node* curr=pq.front();
            pq.pop();
            
            for(auto it:curr->neighbors){
                if(visited[it]==NULL){
                    //never been visited so create a new node
                    visited[it]=new Node(it->val);
                    pq.push(it); //normal BFS
                }
                //Compulsory step push each edge
                visited[curr]->neighbors.push_back(visited[it]);
                
            }
        }
        
        return visited[node];
    }
};