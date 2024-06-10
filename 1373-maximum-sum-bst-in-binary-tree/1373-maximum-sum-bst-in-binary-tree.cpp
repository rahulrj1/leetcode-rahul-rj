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

class NodeInfo{
public:    
    int Min, Max, Sum;
    NodeInfo(int mn, int mx, int sm) {
        Min = mn;
        Max = mx;
        Sum = sm;
    }
};

class Solution {
private:
    int ans;
    NodeInfo* maxSumBSTHelper(TreeNode* root) {
        if(root==NULL) return new NodeInfo(INT_MAX, INT_MIN, 0);
        auto left = maxSumBSTHelper(root->left);
        auto right = maxSumBSTHelper(root->right);
        if(root->val > left->Max && root->val < right->Min) {
            int newSum = left->Sum + right->Sum + root->val;
            ans = max(ans, newSum);
            return new NodeInfo(min(left->Min, root->val), max(right->Max, root->val), newSum);
        }
        return new NodeInfo(INT_MIN, INT_MAX, 0);
        // return new NodeInfo(INT_MIN, INT_MAX, max(left->Sum, right->Sum));
    }
public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        maxSumBSTHelper(root)->Sum;
        return ans;
    }
};