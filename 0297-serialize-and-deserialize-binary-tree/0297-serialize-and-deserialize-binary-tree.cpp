/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root==NULL){
            return "";
        }
        string s="";
        queue<TreeNode*>q; //level ordertraversal
        
        q.push(root);
        while(!q.empty()){
            TreeNode *curr=q.front();
            q.pop();
            if(curr==NULL){
                s.append("#,"); //leaf nodes children will be marked by #
            }
            else{
                s.append(to_string(curr->val)+',');
            }
            if(curr!=NULL){
                q.push(curr->left); //diff from normal level order since we are adding null vaues of left and right also to add # to string SIUU and recreate the tree 
                q.push(curr->right);
            }
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        string str;
        stringstream s(data);
        //str will hold each node '3' seperated by ,
        getline(s,str,','); // ',' is the seperator
        TreeNode *root=new TreeNode(stoi(str)); //string to int bruh stoi
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            //building the tree
            TreeNode *node=q.front();
            q.pop();
            
            getline(s,str,',');
            //get next element left child
            if(str=="#"){
                node->left=NULL; //first left child then right
            }
            else{
                TreeNode *left1=new TreeNode(stoi(str));
                node->left=left1;
                q.push(left1);
            }
            
            //get right child
            
            getline(s,str,',');
            
            if(str=="#"){
                node->right=NULL; //first left child then right
            }
            else{
                TreeNode *right1=new TreeNode(stoi(str));
                node->right=right1;
                q.push(right1);
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));