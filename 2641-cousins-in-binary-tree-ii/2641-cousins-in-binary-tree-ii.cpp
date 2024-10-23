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
    int mp[1000001];
    void dfs1(TreeNode* root, int level) {
        mp[level] += root->val;
        if(root->left) dfs1(root->left, level+1);
        if(root->right) dfs1(root->right, level+1);
    }
    
    void dfs2(TreeNode* root, int level, int psum) {
        root->val = mp[level]-psum;
        int ps = 0;
        if(root->left) ps += root->left->val;
        if(root->right) ps += root->right->val;
        
        if(root->left) dfs2(root->left, level+1, ps);
        if(root->right) dfs2(root->right, level+1, ps);
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs1(root, 1);
        dfs2(root, 1, root->val);
        return root;
    }
};