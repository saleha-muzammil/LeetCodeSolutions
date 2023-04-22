// Soltion to Ad two numbers problem - https://leetcode.com/problems/add-two-numbers/

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

            ListNode* answer = new ListNode(0);  
            ListNode* temp = answer; 

            ListNode* curr1 =  l1 ; 
            ListNode* curr2= l2;

            int reminder =0 ; 
            int value =0 ;
            while (curr1!= nullptr && curr2!=nullptr)
            {
                value = curr1->val+ curr2->val + reminder ; 
                temp->next= new ListNode(value%10);   

                reminder = value/10; 
              
                curr1= curr1-> next ; 
                curr2= curr2-> next ;
                temp = temp-> next ;

            }

                while (curr1!= nullptr)
                {
                    value = curr1->val + reminder;
                    temp-> next= new ListNode(value%10) ;
                    reminder = value/10 ;
                    curr1= curr1-> next ;
                    temp= temp-> next ;
                }

                while (curr2!= nullptr)
                {
                    value = curr2->val + reminder;
                    temp-> next= new ListNode(value%10) ;
                    reminder = value/10 ;


                    curr2= curr2-> next ;
                    temp=temp-> next ;
                }

            if (reminder!=0)
            {
            temp-> next= new ListNode(reminder) ;
            temp= temp->next ;}



            return answer->next  ;
            
        }
    };
