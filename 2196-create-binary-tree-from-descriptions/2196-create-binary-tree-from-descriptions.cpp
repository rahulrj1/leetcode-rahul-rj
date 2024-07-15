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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> hasPar;
        for(vector<int> d: descriptions) {  // parent, child, isLeft
            // if parent not present then create one
            if(mp.find(d[0]) == mp.end()) mp[d[0]] = new TreeNode(d[0]); 
            
            // if child not present then create one
            if(mp.find(d[1]) == mp.end()) mp[d[1]] = new TreeNode(d[1]);
            
            // tag child to parent
            if(d[2] == 1) mp[d[0]]->left = mp[d[1]];
            else mp[d[0]]->right = mp[d[1]];
            
            hasPar.insert(d[1]);
        }
        for(auto it: mp) {
            int curr = it.first;
            if(hasPar.find(curr) == hasPar.end()) return it.second;
        }
        return nullptr;
    }
};