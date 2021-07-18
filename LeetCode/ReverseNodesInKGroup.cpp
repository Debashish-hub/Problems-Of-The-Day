// Reverse Nodes in k-Group

// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a 
// multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.

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
    ListNode* reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last;
        
        while ( first != last )
        {
            auto tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* node = head;
        for (int i=0; i < k; i++)
        {
            if ( ! node  )
                return head; 
            node = node->next;
        }

        ListNode* new_head = reverse( head, node);
        head->next = reverseKGroup( node, k);
        return new_head;
    }
};