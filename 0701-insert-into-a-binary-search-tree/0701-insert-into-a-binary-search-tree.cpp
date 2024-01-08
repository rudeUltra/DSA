/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void insertNode(TreeNode*root,int val,TreeNode* prev){
       if(root==NULL){
           //gOteMMM
           if(val<prev->val){
               TreeNode*temp=new TreeNode(val);
               prev->left=temp;
           }
           else{
               TreeNode*temp=new TreeNode(val);
               prev->right=temp;
           }
           
           return;
       }
        
        prev=root;
        
        //value does not exist Aha
        if(root->val>val){
            insertNode(root->left,val,prev);
        }
        else{
            insertNode(root->right,val,prev);
        }
    }
    
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode*newroot=new TreeNode(val);
            return newroot;
        }
        
        TreeNode*prev=NULL;
        TreeNode*ans=root;
        insertNode(root,val,prev);
        
        return ans;
    }
};