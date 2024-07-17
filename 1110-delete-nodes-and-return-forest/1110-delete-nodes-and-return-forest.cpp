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
    void dfs(TreeNode* root, vector<TreeNode*> &res, unordered_set<int> &del, TreeNode* par, bool isLeft, bool isInsert) {
        if(root == NULL) return;
        
        if(del.find(root->val) != del.end()) {
            if(isLeft) par->left = NULL;
            else par->right = NULL;
            
            dfs(root->left, res, del, root, true, true);
            dfs(root->right, res, del, root, false, true);
        }
        else {
            if(isInsert) res.push_back(root);
                
            dfs(root->left, res, del, root, true, false);
            dfs(root->right, res, del, root, false, false);
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> del; 
        TreeNode* temp = new TreeNode(0, root, NULL);
        for(int &node: to_delete) del.insert(node);
        dfs(root, res, del, temp, true, true);
        return res;
    }
};