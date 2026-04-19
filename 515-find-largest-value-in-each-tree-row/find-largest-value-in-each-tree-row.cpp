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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)return vector<int>{};
        queue<TreeNode*>tree;
        tree.push(root);
        vector<int>ans;
        while(!tree.empty()){
            int nodesOnLvl = tree.size();
            int largest = INT_MIN;
            for(int i = 0; i<nodesOnLvl;++i){
                TreeNode* node = tree.front();
                tree.pop();
                largest = max(largest, node->val);
                if(node->left)tree.push(node->left);
                if(node->right)tree.push(node->right);
            }
            ans.push_back(largest);
        }
        return ans;
    }
};