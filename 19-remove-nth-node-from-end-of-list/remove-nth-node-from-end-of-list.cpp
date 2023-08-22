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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (head== nullptr || n <=0)
        return head ;

        ListNode* current = head  ; 
        int size = 1 ; 

        while (current -> next != nullptr)
        {
            current = current -> next ; 
            size++ ; 
        }

        n= size -n ; 
        ListNode* dummy = new ListNode() ;

        if (n==0)
        {

            if (size==0)
            head= nullptr ; 
            else 
            {   
          //  dummy = head ;     
            head= head-> next ; 
          //  delete dummy ;
            }
            return head  ;
        }

        dummy-> next = head ; 

        for (int i=0 ; i<n && dummy-> next !=nullptr; i++)
        {
            dummy= dummy-> next ; 
        }

        if (dummy->next->next !=nullptr)
        dummy-> next = dummy-> next-> next ; 
        else
        dummy->next = nullptr ; 

        //delete dummy  ;

        return head ;

    }
};