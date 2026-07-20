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

class Codec {
    string join(vector<string>& res, char delim){
        string ans="";
        for(int i =0;i<res.size();i++){
            if(i>0) ans+=delim;
            ans+= res[i];
        }
        return ans;
    }

    vector<string> split(string& data, char delim){
        vector<string> ans;
        stringstream ss(data);
        string item;
        while(getline(ss,item,delim)){
            ans.push_back(item);
        }
        return ans;
    }

    void dfsSerial(TreeNode* root, vector<string>& res){
        if(!root){
            res.push_back("N");
            return;
        };
        res.push_back(to_string(root->val));
        dfsSerial(root->left,res);
        dfsSerial(root->right,res);

    }

    TreeNode* dfsDeserial(vector<string>& res,int& ind){
        if(res[ind]=="N") {
            ind++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(res[ind]));
        ind++;
        root->left = dfsDeserial(res,ind);
        root->right = dfsDeserial(res,ind);
        return root;
        

    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerial(root,res);
        return join(res,',');
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> res = split(data,',');
        int ind = 0;
        TreeNode* root = dfsDeserial(res,ind);
        return root;
        
    }
};
