class Solution {
private:
    ListNode* getmiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next; 
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head)
    {
        if(head -> next == NULL)
        {
            return true;
        }
        // step1 = getmiddle
        ListNode* middle = getmiddle(head);
        
        // step2 = getting LL reversed after middle
        ListNode* temp = middle->next;
        middle->next = reverse(temp);
        
        // step3 comparing both halves of LL
        ListNode* head1 = head;
        ListNode* head2 = middle->next;
        
        while(head2 != NULL)
        {
            if(head1->val != head2->val)
            {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
            
        }
        // step4 making LL same as input
//         temp = middle->next;
//         middle->next = reverse(middle);
        
        // step5 returning value
        return true;
        
    }
};
