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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val==key){
            if(height(root->left)>=height(root->right)){
                TreeNode *q=inorderpre(root->left);
                if(q==NULL){
                    return NULL;
                }
                root->val=q->val;
                root->left=deleteNode(root->left,q->val);
            }
            else{
                TreeNode *p=inordersucc(root->right);
                if(p==NULL){
                    return NULL;
                }
                root->val=p->val;
                root->right=deleteNode(root->right,p->val);
            }
        }
        return root;
    }
    int height(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int x=height(root->left);
        int y=height(root->right);
        
        return 1+max(x,y);
    }
    TreeNode *inorderpre(TreeNode *root){
        while(root && root->right!=NULL){
            root=root->right;
        }
        return root;
    }
     TreeNode *inordersucc(TreeNode *root){
        while(root && root->left!=NULL){
            root=root->left;
        }
        return root;
    }
};