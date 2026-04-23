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
    int closestValue(TreeNode* root, double target) {
        vector<int>nums;
        inOrder(root, nums);

        int closest = nums[0];
        for(int n : nums){
            if(abs(n-target) < abs(closest-target)) closest = n;
        }
        return closest;

    }

    void inOrder(TreeNode* node, vector<int>& nums){
        if(node == nullptr) return;
        inOrder(node->left,nums);
        nums.push_back(node->val);
        inOrder(node->right, nums);
    }
};