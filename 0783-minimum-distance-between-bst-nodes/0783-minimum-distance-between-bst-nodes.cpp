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
    pair<int, int> helper(TreeNode* root, int &ans) {
        pair<int, int> p = {root->val, root->val};
        if(root->left) {
            auto temp = helper(root->left, ans);
            ans = min(ans, (root->val - temp.second));
            p.first = min(p.first, temp.first);
        } 
        if(root->right) {
            auto temp = helper(root->right, ans);
            ans = min(ans, temp.first - root->val);
            p.second = max(p.second, temp.second);
        }
        return p;
    }
    
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        helper(root, ans);
        return ans;
    }
};