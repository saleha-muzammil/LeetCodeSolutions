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

        ListNode* current2= new ListNode() ; 
        current2-> next = head ; 
        n= size -n ; 

        if (n==0 && size ==1 )
        {
            head= nullptr ; 
            return head  ;
        }

        else if (n==0)
        {
            head= head-> next ; 
            return head  ;
        }

        for (int i=0 ; i<n && current2-> next !=nullptr; i++)
        {
            current2= current2-> next ; 
        }

        ListNode* node = current2 ; 

        if (current2-> next!= nullptr && current2->next->next !=nullptr)
        current2 -> next = current2-> next-> next ; 
        else
        current2->next = nullptr ; 

       // delete node ;

        return head ;

    }
};