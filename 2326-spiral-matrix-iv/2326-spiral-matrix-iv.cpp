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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int>(n,-1));
        int top=0,left=0,right=n-1,down=m-1;
        int dir=0;
        while(head && top<=down && left<=right)
        {
            if(dir==0)
            {
                for(int i=left;i<=right && head;i++)
                {
                    matrix[top][i]=head->val;
                    head=head->next;
                }
                top++;
                
            }
            else if(dir==1)
            {
                for(int i=top;i<=down && head;i++)
                {
                    matrix[i][right]=head->val;
                    head=head->next;
                }
                right--;
                
            }
            else if(dir==2)
            {
                for(int i=right;i>=left && head;i--)
                {
                    matrix[down][i]=head->val;
                    head=head->next;
                }
                down--;
                
            }
            else 
            {
                for(int i=down;i>=top && head;i--)
                {
                    matrix[i][left]=head->val;
                    head=head->next;
                }
                left++;
                
            }
            
            dir=(dir+1)%4;
        }
        return matrix;
        
    }
};