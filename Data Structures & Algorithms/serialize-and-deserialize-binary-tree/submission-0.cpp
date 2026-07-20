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
    void dfsSerial(TreeNode* node, vector<string>& res){
        if(!node){
            res.push_back("N");
            return;
        }
        res.push_back(to_string(node->val));
        dfsSerial(node->left,res);
        dfsSerial(node->right,res);
    }

    TreeNode* dfsDeserial(vector<string>& vals,int& i){
        if(vals[i]=="N"){
            i++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsDeserial(vals,i);
        node->right = dfsDeserial(vals,i);
        return node;
    }
    
    vector<string> split(const string &s, char delim){
        vector<string> elems;
        stringstream ss(s);
        string item;
        while(getline(ss,item,delim)){
            elems.push_back(item);
        }
        return elems;
    }

    string join(const vector<string>& v, const string& delim) {
        string result;

        for (int i = 0; i < v.size(); i++) {
            if (i > 0) {
                result += delim;
            }

            result += v[i];
        }

        return result;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerial(root,res);
        return join(res,",");
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data,',');
        int i =0;
        return dfsDeserial(vals,i);
        
    }

};
