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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int k=0;
        return f(preorder,inorder,k,0,n-1);
    }
    
    TreeNode* f(vector<int>&preorder,vector<int>&inorder,int &k,int left,int right){
        //siu
        if(left>right){
            return NULL; //No
        }
        int cut=left;
        while(inorder[cut]!=preorder[k]){
            cut++;
        }
        
        TreeNode*middle=new TreeNode(preorder[k]);
        k++;
        
        middle->left=f(preorder,inorder,k,left,cut-1);
        middle->right=f(preorder,inorder,k,cut+1,right);
        
        return middle;
        
    }
};