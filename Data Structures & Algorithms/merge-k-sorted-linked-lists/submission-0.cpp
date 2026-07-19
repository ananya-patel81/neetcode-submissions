/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    ListNode* mergetwolists(ListNode* l1, ListNode* l2){
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val < temp2->val){
                curr->next = temp1;
                curr = curr->next;
                temp1= temp1->next;
            }

            else{
                curr->next = temp2;
                curr = curr->next;
                temp2= temp2->next;
            }
        }

        while(temp1!=NULL){
            curr->next = temp1;
            curr = curr->next;
            temp1= temp1->next;
        }

        while(temp2!=NULL){
            curr->next = temp2;
            curr = curr->next;
            temp2= temp2->next;
        }

        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        for(int i =1;i<lists.size();i++){
            lists[i] = mergetwolists(lists[i-1],lists[i]);
        }

        return lists.back();

        
    }
};
