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
    vector<int> helper(TreeNode* root, int &distance) {
        if(!root) return vector<int> (12, 0);
        else if(!root->left && !root->right) {
            vector<int> res(12, 0);
            res[0] = 1;
            return res;
        }
        
        vector<int> res(12, 0);
        vector<int> left = helper(root->left, distance);
        vector<int> right = helper(root->right, distance);
        
        for(int i=0; i<10; i++) res[i+1] = left[i] + right[i];
        
        // calculating the good pairs for this case
        res[11] = left[11] + right[11];
        
        for(int d1 = 0; d1 <= distance; d1++) {
            for(int d2 = 0; d2 <= distance; d2++) {
                if(d1+d2+2 <= distance) {
                    res[11] += left[d1]*right[d2];
                }
            }
        }
        
        return res;
    }
    
    int countPairs(TreeNode* root, int distance) {
        return helper(root, distance)[11];
    }
};