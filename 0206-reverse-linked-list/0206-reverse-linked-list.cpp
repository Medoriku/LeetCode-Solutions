class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: If the list is empty or has only one node, no need to reverse
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* prev = nullptr;  // This will be the new tail (initially `nullptr`)
        ListNode* curr = head;     // Start with the head of the list
        
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;  // Store the next node
            curr->next = prev;                // Reverse the current node's next pointer
            prev = curr;                      // Move prev and curr one step forward
            curr = nextTemp;
        }
        
        return prev;  // prev is the new head of the reversed list
    }
};
