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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        int n=0;
        ListNode *p=head;
        while(p)
        {
            p=p->next;
            n++;
        }
        
        k=k%n;
        n-=k;
        if(k==0) return head;

        
        
        ListNode *list1=head;
        ListNode *list2;
        n--;
        
        while(n--)
        {
            
            list1=list1->next;
            
        }
        list2=list1->next;
        list1->next=nullptr;
        ListNode *temp=list2;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=head;
        return list2;
    }

};