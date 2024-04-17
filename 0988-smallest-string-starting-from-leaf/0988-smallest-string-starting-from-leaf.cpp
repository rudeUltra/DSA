class Solution {
	string ans;
public:
	void helper(TreeNode *root,string &s){
		if(!root) return;
		s.push_back(root->val+'a');
		if(root->left==root->right){
			 string str=s;
			 reverse(str.begin(),str.end());
			 if(ans.empty() || str<ans)
				 ans=str;
		}
		helper(root->left,s);
		helper(root->right,s);
		s.pop_back();
        //we can also do this with set as set will always keep the strings in sorted order
        //In the end just return *set.begin()!
	}
	string smallestFromLeaf(TreeNode* root) {
		string s="";
		helper(root,s);
		return ans;
	}
};