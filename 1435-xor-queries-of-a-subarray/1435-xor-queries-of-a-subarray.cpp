class Solution {
public:
    vector<int> xorQueries(vector<int>& ar, vector<vector<int>>& q) {
        int n=ar.size();
        int arr[n];
        arr[0]=ar[0];
        for(int i=1;i<n;i++)
        {
            arr[i]=arr[i-1]^ar[i];
        }
        vector<int> res;
        int l=q.size();
        for(int i=0;i<l;i++)
        {
            int L=q[i][0];
            int R=q[i][1];
            if(L==0)
            {
                res.push_back(arr[R]);
            }
            else
            {
                res.push_back(arr[L-1]^arr[R]);
            }
        }
        return res;
        
    }
};