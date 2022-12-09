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
    void helper(TreeNode* root, int &ans, int manc, int Manc) {
        manc = min(root->val, manc);
        Manc = max(root->val, Manc);
        ans = max({ans, abs(root->val - manc), abs(root->val - Manc)});
        
        if(root->left) helper(root->left, ans, manc, Manc);
        if(root->right) helper(root->right, ans, manc, Manc);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        helper(root, ans, root->val, root->val);
        return ans;
    }
};