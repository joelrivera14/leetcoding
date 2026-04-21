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
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> tree;
        tree.push(root);
        int sum = 0;
        while(!tree.empty()){
            int n = tree.size();
            for(int i = 0; i<n; ++i){
                TreeNode* node = tree.front();
                tree.pop();
                if(node->val>=low && node->val<=high)sum+=node->val;
                if(node->left)tree.push(node->left);
                if(node->right)tree.push(node->right);
            }
        }
        return sum;
    }
};