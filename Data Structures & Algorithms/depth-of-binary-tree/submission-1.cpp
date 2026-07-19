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
    void getdepth(TreeNode* root, int count, int& max_count){
        if(!root){
            max_count = max(max_count,count);
            return;
        }
        count= count+1;
        getdepth(root->left,count,max_count);
        getdepth(root->right,count,max_count);
        
    }
public:
    int maxDepth(TreeNode* root) {
        int max_count = INT_MIN;
        int count = 0;
        getdepth(root, count, max_count);
        return max_count;
        
    }
};
