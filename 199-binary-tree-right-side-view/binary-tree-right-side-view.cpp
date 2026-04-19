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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)return vector<int>{};
        queue<TreeNode*> tree;
        vector<int> ans;
        tree.push(root);
        while(!tree.empty()){
            int nodesOnLvl = tree.size();
            ans.push_back(tree.back()->val);
            for(int i = 0; i < nodesOnLvl; ++i){
                TreeNode* node = tree.front();
                tree.pop(); 
                if(node->left)tree.push(node->left);
                if(node->right)tree.push(node->right);
            }
        }
        return ans;
    }
};