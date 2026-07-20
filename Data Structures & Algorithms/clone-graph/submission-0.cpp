/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> mpp;
        Node* cloneRoot = new Node(node->val);
        mpp[node]= cloneRoot;

        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* og = q.front();
            q.pop();
            Node* copy = mpp[og];
            for(Node* n : og->neighbors){
                if(mpp.find(n)!=mpp.end()){
                    copy->neighbors.push_back(mpp[n]);
                }
                else{
                    Node* ncopy = new Node(n->val);
                    mpp[n]=ncopy;
                    copy->neighbors.push_back(mpp[n]);
                    q.push(n);
                }
            }
        }
        return mpp[node];   
    }
};
