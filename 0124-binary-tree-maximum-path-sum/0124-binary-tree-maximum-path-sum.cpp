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
    int findans(TreeNode* root, int &ans) {
        if(root == NULL) return 0;
        int l = findans(root->left, ans);
        int r = findans(root->right, ans); 
        int tempans = max(root->val, root->val + max(l, r));
        ans = max(ans, max(tempans, root->val + l + r));
        return tempans;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findans(root, ans);
        return ans;
    }
};