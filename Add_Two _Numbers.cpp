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
        ListNode* head = new ListNode;
        ListNode* l3 = head;
        int cin{}, nval{};

        ListNode* last;
        while(l1 && l2) {
            l3->next = new ListNode;

            nval = l1->val + l2->val;
            l3->val = nval + cin;
            if (l3->val > 9) {
                l3->val -= 10; 
                cin = 1;
            } 

            else { cin = 0; }
            
            last = l3;
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            nval = l1->val + cin;
            if (nval > 9) {nval -= 10; cin = 1;}
            else { cin = 0;}
            l3->val = nval;
            l1 = l1->next;

            last = l3;
            l3->next = new ListNode;
            l3 = l3->next;
        }

        while(l2) {
            nval = l2->val + cin;
            if (nval > 9) {nval -= 10; cin = 1;}
            else { cin = 0;}
            l3->val = nval;
            l2 = l2->next;

            last = l3;
            l3->next = new ListNode;
            l3 = l3->next;
        }

        if(cin) {
            l3->val = 1;
        }
        else {
            last->next = nullptr;
            delete l3;
        }

        return head;
    }
};
