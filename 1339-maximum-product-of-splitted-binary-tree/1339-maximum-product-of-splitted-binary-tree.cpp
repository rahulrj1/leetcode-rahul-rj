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
    int findSum(TreeNode* root) {
        int sum = root->val;
        if(root->left) sum += findSum(root->left);
        if(root->right) sum += findSum(root->right);
        return sum;
    }
    
    int findAns(TreeNode* root, long long &ans, int sum) {
        int temp = root->val;
        if(root->left) temp += findAns(root->left, ans, sum);
        if(root->right) temp += findAns(root->right, ans, sum);
        ans = max(ans, 1LL*temp*(sum - temp));
        return temp;
    }
    
    int maxProduct(TreeNode* root) {
        long long ans = -1e18;
        int sum = findSum(root);
        findAns(root, ans, sum);
        return ans%1000000007;
    }
};