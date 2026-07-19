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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vector<vector<int>> bfs;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int val = node->val;
            int level = q.front().second;
            q.pop();
            if(bfs.size()==level){
                bfs.push_back({});
            }
            bfs[level].push_back(val);
            if(node->left) q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }
        return bfs;
    }
};
