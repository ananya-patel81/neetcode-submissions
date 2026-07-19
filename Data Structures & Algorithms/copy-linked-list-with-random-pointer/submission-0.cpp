/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    void createCopy(Node* head){
        // Node* temp = dummy;
        Node* curr = head;
        while(curr!=NULL){
            Node* copy = new Node(curr->val);
            Node* nextNode = curr->next;
            curr->next = copy;
            copy->next = nextNode;
            // temp->next = curr;
            curr= nextNode;
            // temp = 
        }
        
    }

    void connectRandomCopy(Node* head){
        Node* curr = head;
        while(curr!=NULL){
            //Node* nextNode = curr->next->next;
            Node* copyNode = curr->next;
            if(curr->random) {
                copyNode->random = curr->random->next;
            }
            else copyNode->random = NULL;

            curr = copyNode->next;

        }
    }

    void makeConnections(Node* head, Node* dummy){
        Node* temp = dummy;
        Node* curr = head;
        while(curr!=NULL){
            Node* copynode = curr->next;
            temp->next = copynode;
            temp = temp->next;
            Node* nextnode = curr->next->next;
            //copynode->next = nextnode->next;
            curr->next = nextnode;
            curr = nextnode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        //create node copy
        //add randoms
        //connect all
        Node* dummy = new Node(-1);
        createCopy(head);
        connectRandomCopy(head);
        makeConnections(head,dummy);
        return dummy->next;
        
    }
};
