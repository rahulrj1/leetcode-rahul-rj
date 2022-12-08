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
    void helper(vector<int> &ans, TreeNode* root) {
        if(root->left) helper(ans, root->left);
        if(root->left == NULL && root->right == NULL) ans.push_back(root->val);
        if(root->right) helper(ans, root->right);
    }
    
    vector<int> preOrder(TreeNode* root){
        vector<int> ans;
        helper(ans, root);
        return ans;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1 = preOrder(root1);
        vector<int> v2 = preOrder(root2);
        if(v1.size() != v2.size()) return false;
        for(int i=0; i<v1.size(); i++) {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
};