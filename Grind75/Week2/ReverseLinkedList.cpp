
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == nullptr || head->next ==nullptr){
            return head;
        }
        ListNode* front = head;
        ListNode* cur = nullptr;

        while(front!=nullptr){
            ListNode* temp = front;
            front = front->next;
            temp->next = cur;
            cur = temp;
        }
        return cur;
    }
};
