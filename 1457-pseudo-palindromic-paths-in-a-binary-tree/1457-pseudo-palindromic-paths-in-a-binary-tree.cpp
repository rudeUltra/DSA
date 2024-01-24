class Solution {
public:
    void rec(TreeNode* root) {
        if (!root)
            return;
        
        m[root->val]++;
        
        // If we got to a leaf - check if the path can be a polindrome
        if (!root->left && !root->right) {
            int odd = 0;
            for (auto a : m)
                if (a.second % 2 == 1)
                    odd++;

            if (odd <= 1)
                res++;
        }
        
        rec(root->left);
        rec(root->right);
        m[root->val]--; //dont erase the value decrement it xD big brain
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        rec(root);
        return res;
    }
    
private:
    int res = 0;
    unordered_map<int, int> m;
};