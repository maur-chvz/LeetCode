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
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) {return 0;}

        int out = root->val;

        auto dfs = [&](this const auto& self, TreeNode* src) { 
            if(src == nullptr) {return 0;}

            int left = max(0, self(src->left));
            int right = max(0, self(src->right));
            
            out = max(out, left + right + src->val);
            
            return max(left, right) + src->val;
        };

        dfs(root);
        return out;
    }
};
