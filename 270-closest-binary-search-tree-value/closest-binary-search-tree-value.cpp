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
    vector<int> nums;
    int closestValue(TreeNode* root, double target) {
        inOrder(root);
        int close = nums[0];
        for(int n : nums){
            if(abs(target-n) < abs(target-close)) close = n;
        }
        return close;
    }

    void inOrder(TreeNode* root){
        if(root == nullptr) return;
        inOrder(root->left);
        nums.push_back(root->val);
        inOrder(root->right);
    }
};