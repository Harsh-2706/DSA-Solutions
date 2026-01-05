class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for (int i = 0; i < k; i++) {
            if (!cur) return head;
            cur = cur->next;
        }
        ListNode* prev = nullptr;
        cur = head;
        for (int i = 0; i < k; i++) {
            auto nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        head->next = reverseKGroup(cur, k);
        return prev;
    }
};
