// Reverse Linked List II


// Given the head of a singly linked list and two integers left and right where left <= right, 
// reverse the nodes of the list from position left to position right, and return the reversed list.

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode* prev;
        ListNode* curr = head;
        
        int n = left;
        
        while(--n){
            prev = curr;
            curr = curr->next;
        }
        ListNode* start = prev;
        ListNode* end = curr;
        
        ListNode* next;
        n = right - left +1;
        
        while(n--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(start) 
            start->next = prev;
        else head = prev;
        end->next = curr;
        
        return head;  
    }
};