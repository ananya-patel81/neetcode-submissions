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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2==nullptr) return list1;

        ListNode* dummy = new ListNode();
        ListNode* dummyHead = dummy;
        
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                ListNode* curr = new ListNode(temp1->val);
                dummy->next = curr;
                dummy = dummy->next;
                temp1= temp1->next;
            }
            else{
                ListNode* curr = new ListNode(temp2->val);
                dummy->next = curr;
                dummy = dummy->next;
                temp2= temp2->next;
            }
        }

        while(temp1!=NULL){
            ListNode* curr = new ListNode(temp1->val);
            dummy->next = curr;
            dummy = dummy->next;
            temp1= temp1->next;
        }

        while(temp2!=NULL){
            ListNode* curr = new ListNode(temp2->val);
            dummy->next = curr;
            dummy = dummy->next;
            temp2= temp2->next;
        }

        return dummyHead->next;
        
    }
};
