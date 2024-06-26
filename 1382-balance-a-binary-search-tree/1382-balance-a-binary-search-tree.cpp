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
    TreeNode* makeBST(vector<int> &v, int st, int end) {
        if(st == end) return new TreeNode(v[st]);
        if(end < st) return nullptr;
        int m = (st+end)/2;
        TreeNode* z = new TreeNode(v[m]);
        z->left = makeBST(v, st, m-1);
        z->right = makeBST(v, m+1, end);
        return z;
    }
    
    void inorder(TreeNode* root, vector<int> &v) {
        if(root == NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        
        int n = v.size();
        return makeBST(v, 0, n-1);
    }
};