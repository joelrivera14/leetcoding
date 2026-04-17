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
int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
    int dfs(TreeNode* node){
        if(node == nullptr) return -1;
        int leftPath = dfs(node->left);
        int rightPath = dfs(node->right);
        diameter = max(diameter , leftPath+rightPath+2);
        return max(leftPath,rightPath)+1;
    }
};