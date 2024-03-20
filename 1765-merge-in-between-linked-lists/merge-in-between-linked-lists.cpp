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
    ListNode* mergeInBetween(ListNode* list1, int i, int j, ListNode* list2) {
          ListNode* ith = list1; 
        ListNode* jth = list1;
        while(i>1){
            ith = ith->next;
            i--;
        }
        while(j>0){ 
            jth = jth->next;
            j--;
        }
        ith->next = list2;
        while(list2->next!=NULL){
            list2 = list2->next; 
        }
        list2->next = jth->next; 
        return list1;
        
    }
};