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
    TreeNode* findLCA(TreeNode* root, int sv, int dv) {
        if(root == NULL || root->val == sv || root->val == dv) return root;
        TreeNode *l = findLCA(root->left, sv, dv);
        TreeNode *r = findLCA(root->right, sv, dv);
        if(l == NULL) return r;
        if(r == NULL) return l;
        return root;
    }
    
    bool dfs(TreeNode *root, string &res, int z) {
        if(root == NULL) return false;
        
        if(root->val == z) return true;
        
        res += 'L';
        if(dfs(root->left, res, z)) return true;
        res.pop_back();
        res += 'R';
        if(dfs(root->right, res, z)) return true;
        res.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue); // find LCA
        
        string lcaToStart = "", lcaToDest = "";
        dfs(lca, lcaToStart, startValue);
        dfs(lca, lcaToDest, destValue);
        
        for(char &c: lcaToStart) c = 'U';
        
        return lcaToStart + lcaToDest;
    }
};