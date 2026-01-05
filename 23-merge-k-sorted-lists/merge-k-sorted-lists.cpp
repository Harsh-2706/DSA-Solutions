class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,
            function<bool(ListNode*, ListNode*)>> pq(
            [](auto a, auto b){ return a->val > b->val; });

        for (auto l : lists) if (l) pq.push(l);

        ListNode dummy(0), *cur = &dummy;
        while (!pq.empty()) {
            auto n = pq.top(); pq.pop();
            cur->next = n; cur = cur->next;
            if (n->next) pq.push(n->next);
        }
        return dummy.next;
    }
};
