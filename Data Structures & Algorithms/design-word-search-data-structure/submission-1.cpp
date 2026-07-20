class Node{
public:
    Node* links[26]={nullptr};
    bool flag = false;

    void putKey(char ch, Node* node){
        links[ch-'a']=node;
    }

    bool containsKey(char ch){
        return links[ch-'a'] || ch=='.';
    }

    Node* getKey(char ch){
        return links[ch-'a'];
    }

    void markEnd(){
        flag = true;
    }
};

// class Trie{
//     Node* root;
//     Trie(){
//         root = new Node();
//     }

//     void insertWord()
// }
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node();
        
    }
    
    void addWord(string word) {
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->putKey(ch,new Node());
            }
            node = node->getKey(ch);
        }
        node->markEnd();
        
    }
    
    bool search(string word) {
        Node* node = root;
        return dfs(word, 0, node);
    }

private:
    bool dfs(string& word,int j, Node* root){
        Node* curr = root;
        for(int i=j;i<word.size();i++){
            char ch = word[i];
            if(ch=='.'){
                for(Node* node : curr->links){
                    if(node!=nullptr && dfs(word,i+1,node)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(curr->containsKey(ch)){
                    curr = curr->getKey(ch);
                }
                else return false;
            }
        }
        return curr->flag;
    }
};
