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
    int getLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
                temp = temp -> next; 
                len++;
        }
        return len;
    }
   
    ListNode* reverseKGroup(ListNode* head, int k) {

        int count=0;
        int len =getLength(head);
        if(head==NULL||k>len){           //check initial condition
            return head;
        }
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward =curr->next;

        while(count<k){                    //reverse first k nodes
            forward =curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }

        if(forward!=NULL){                 //if still nodes are left ,reverse next k nodes by recursion function
            head->next=reverseKGroup(forward,k);
        }

        return prev;                     // return prev ,the head of reversed node 
        
    }
};