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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)return vector<vector<int>>{};
        vector<vector<int>>ans;
        deque<TreeNode*> tree;
        tree.push_back(root);
        tree.push_back(nullptr);
        deque<int>lvlList;
        bool isOrderLeft = true;
        while(!tree.empty()){
            TreeNode* node = tree.front();
            tree.pop_front();
            if(node != nullptr){
                if(isOrderLeft){
                    lvlList.push_back(node->val);
                }else{
                lvlList.push_front(node->val);
            }    
            if(node->left)tree.push_back(node->left);
            if(node->right)tree.push_back(node->right);
            }else{
                ans.push_back(vector<int>{lvlList.begin(), lvlList.end()});
                lvlList.clear();
                if(!tree.empty())tree.push_back(nullptr);
                isOrderLeft = !isOrderLeft;
            }   
        }
        return ans;
    }
};