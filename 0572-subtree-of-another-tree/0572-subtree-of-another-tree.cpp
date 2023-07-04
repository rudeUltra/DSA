class Solution {
public:
   
   bool isSametree(TreeNode* s, TreeNode* t){
       if(!s || !t){
           return s==NULL && t==NULL;
       } 
       else if(s->val == t->val){    
           return isSametree(s->left,t->left) && isSametree(s->right,t->right);
       }
       else{
           return false;
       }
   }
   bool isSubtree(TreeNode* s, TreeNode* t) {
         if(!s){
             return false;
         }   
         else if(isSametree(s,t)){
             return true;
         }
         else{
             return isSubtree(s->left,t) || isSubtree(s->right,t);
         }
   }
};