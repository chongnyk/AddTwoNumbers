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
        int i = 1;
        ListNode* iterOne = l1;
        ListNode* iterTwo = l2;
        int lengthOne = 0;
        int lengthTwo = 0;
        int carry = 0;
        int digit = 0;
        int sum = 0;
        while(i < 100 && lengthOne >= 0 && lengthTwo >= 0){
            sum = iterOne->val + iterTwo->val + carry;
            digit = sum % 10;
            carry = (sum - digit)/10;
            iterOne->val = digit;
            iterTwo->val = digit;
            if(iterOne->next != nullptr){
                iterOne = iterOne->next;
                lengthOne++;
            }
            else {
                lengthOne = -1;
            }
            if(iterTwo->next != nullptr){
                iterTwo = iterTwo->next;
                lengthTwo++;
            }
            else {
                lengthTwo = -1;
            }
            i++;
        }

        if(lengthOne == -1 && lengthTwo == -1){
            if(carry != 0) {
                iterOne->next = new ListNode(carry, nullptr);
            }
            return l1;
        }
        else if(lengthOne == -1){
            while(i < 100 && iterTwo != nullptr){
                sum = iterTwo->val + carry;
                digit = sum % 10;
                carry = (sum - digit)/10;
                iterTwo->val = digit;
                if(iterTwo->next != nullptr){
                    iterTwo = iterTwo->next;
                }
                else {
                    if(carry != 0) iterTwo->next = new ListNode(carry, nullptr);
                    iterTwo = nullptr;
                }
                i++;
            }
            return l2;
        }
        else if(lengthTwo == -1){
            while(i < 100 && iterOne != nullptr){
                sum = iterOne->val + carry;
                digit = sum % 10;
                carry = (sum - digit)/10;
                iterOne->val = digit;
                if(iterOne->next != nullptr){
                    iterOne = iterOne->next;
                }
                else {
                    if(carry != 0) iterOne->next = new ListNode(carry, nullptr);
                    iterOne = nullptr;
                }
                i++;
            }
            return l1;
        }
        
        return l1;
    }
};
