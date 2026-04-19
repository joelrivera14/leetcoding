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
    int deepestLeavesSum(TreeNode* root) {
       queue<TreeNode*>tree;
       tree.push(root);
       vector<int>sums;
       int sum = 0;
       while(!tree.empty()){
        int nodesOnLvl = tree.size();
        for(int i = 0; i<nodesOnLvl; ++i){
            TreeNode* node = tree.front();
            tree.pop();
            sum+=node->val;
            if(node->left)tree.push(node->left);
            if(node->right)tree.push(node->right);
        }
        sums.push_back(sum);
        sum=0;
       } 
       return sums.back();
    }
};