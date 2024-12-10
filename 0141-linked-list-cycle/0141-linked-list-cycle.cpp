class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false; // No cycle possible
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // Move slow pointer by 1 step
            fast = fast->next->next; // Move fast pointer by 2 steps
            
            if (slow == fast) {
                return true; // Cycle detected
            }
        }
        
        return false; // No cycle found
    }
};
