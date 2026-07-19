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
    TreeNode* mybuildTree(vector<int>& preOrder,int preStart, int preEnd, vector<int>& inorder,int inStart,int inEnd,map<int,int> in_map){
        if(preStart>preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preOrder[preStart]);
        int inRoot = in_map[preOrder[preStart]];
        int numsleft = inRoot - inStart;

        root->left = mybuildTree(preOrder,preStart+1,preStart+numsleft,inorder,inStart, inRoot-1,in_map);
        root->right = mybuildTree(preOrder,preStart+numsleft+1,preEnd,inorder,inRoot+1, inEnd, in_map);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> in_map;
        for(int i=0;i<inorder.size();i++){
            in_map[inorder[i]]=i;
        }
        TreeNode* root = mybuildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size(),in_map);
        return root;

        
    }
};
