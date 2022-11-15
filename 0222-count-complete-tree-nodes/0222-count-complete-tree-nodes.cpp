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
    int countNodes(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        if(root != NULL) q.push(root);
        while(!q.empty()) {
            ans++;
            auto t = q.front(); q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        return ans;
    }
};