class Node{
public:
    Node* links[26]={nullptr};
    bool fl = false;

    bool containsKey(char ch){
        return links[ch-'a'];
    }

    Node* getKey(char ch){
        return links[ch-'a'];
    }

    void putKey(char ch, Node* node){
        links[ch-'a'] = node;
    }

    void markEnd(){
        fl = true;
    }
};



class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->putKey(ch,new Node());
            }
            node= node->getKey(ch);
        }
        node->markEnd();
        
    }
    
    bool search(string word) {
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return false;
            }
            node= node->getKey(ch);
        }
        return node->fl;
        
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch : prefix){
            if(!node->containsKey(ch)){
                return false;
            }
            node= node->getKey(ch);
        }
        return true;

        
    }
};
