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
    ListNode*reverse(ListNode*head1){
    ListNode*curr=head1;
      ListNode*next=NULL;
      ListNode*prev=NULL;
      while(curr){
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
      }
      return prev;
   }
   void print(ListNode*head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    return;
   }
   int count(ListNode*head){
        int ans =0;
        while(head){
            ans++;
            head=head->next;
        }
        return ans;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
        return head;
        int total = count(head);
        if(left ==1 && right == total){
            return reverse(head);
        }
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode*temp=head;
        ListNode*prev=NULL;
      while(left>1){
        prev=temp;
        temp=temp->next;
        left--;
        }
        // prev->next=NULL
       ListNode*temp1=head;
        while(right>1){
            temp1=temp1->next;
            right--;
        }
         ListNode*next=temp1->next;
         temp1->next=NULL;
        ListNode *tempUtil = temp;
        while(temp!=temp1){
            temp=temp->next;
        }
        temp->next = NULL;
        ListNode*ans=reverse(tempUtil);
        if(prev!=NULL)
            prev->next=NULL;
        print(ans);cout<<endl;
        print(prev);cout<<endl;
        print(next);
        if(prev!=NULL)
            prev->next = ans;
        else{
            head=ans;
        }
        while(ans->next!=NULL){
            ans=ans->next;
        }
        ans->next = next;
        return head;
    }
};