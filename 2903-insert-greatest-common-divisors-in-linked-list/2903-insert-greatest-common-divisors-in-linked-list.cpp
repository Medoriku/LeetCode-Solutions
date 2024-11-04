#include <numeric> // For std::gcd

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // If the list is empty or has only one node, no insertion is needed
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* current = head;
        
        // Traverse the linked list
        while (current && current->next) {
            // Calculate GCD of current and next node's values
            int gcdValue = std::gcd(current->val, current->next->val);
            
            // Create a new node with the GCD value
            ListNode* gcdNode = new ListNode(gcdValue);
            
            // Insert the new node between current and current->next
            gcdNode->next = current->next;
            current->next = gcdNode;
            
            // Move to the next pair (skip the newly added node)
            current = gcdNode->next; // Now current points to the next node after gcdNode
        }
        
        return head; // Return the modified list
    }
};
