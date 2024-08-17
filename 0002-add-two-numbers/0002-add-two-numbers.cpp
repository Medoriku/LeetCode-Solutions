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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);  // Dummy head node to simplify edge cases
        ListNode* current = dummyHead;          // Pointer to construct the new linked list
        int carry = 0;                          // Initialize carry to 0

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int x = (l1 != nullptr) ? l1->val : 0;  // Get value from l1 or 0 if l1 is nullptr
            int y = (l2 != nullptr) ? l2->val : 0;  // Get value from l2 or 0 if l2 is nullptr
            int sum = carry + x + y;                // Calculate the sum of the values and the carry
            carry = sum / 10;                       // Update the carry
            current->next = new ListNode(sum % 10); // Create a new node with the sum's digit
            current = current->next;                // Move to the next node
            
            if (l1 != nullptr) l1 = l1->next;       // Move to the next node in l1
            if (l2 != nullptr) l2 = l2->next;       // Move to the next node in l2
        }

        return dummyHead->next;  // Return the next node after the dummy head
    }
};
