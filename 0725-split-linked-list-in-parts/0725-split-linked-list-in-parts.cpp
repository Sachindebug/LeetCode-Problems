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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0, count, temp;
        ListNode *trav = head;
        ListNode *tmp = NULL;
        vector<ListNode*> v;
        
        while(trav != NULL)
        {
            trav = trav->next;
            size++;
        }
        
        count = size/k;
        
        if(count < 1)
        {
            trav = head;
            for(int i=0; i<k; i++)
            {
                if(size == 0)
                {
                    tmp = NULL;
                    v.push_back(tmp);
                }
                else
                {
                    tmp = trav;
                    trav = trav->next;
                    tmp->next = NULL;
                    v.push_back(tmp);
                    size--;
                }
            }
        }
        else
        {
            temp = floor(count);
            temp = temp*k;
            temp = size-temp;
            trav = head;
            for(int i=0; i<k; i++)
            {
                if(temp == 0)
                {
                    v.push_back(trav);
                    for(int j=0; j<floor(count)-1; j++)
                    {
                        trav = trav->next;
                    }
                    tmp = trav;
                    trav = trav->next;
                    tmp->next = NULL;
                }
                else
                {
                    v.push_back(trav);
                    for(int j=0; j<floor(count); j++)
                    {
                        trav = trav->next;
                    }
                    tmp = trav;
                    trav = trav->next;
                    tmp->next = NULL;
                    temp--;

                }
                  
            }
        }
        
        return v;
    }
};