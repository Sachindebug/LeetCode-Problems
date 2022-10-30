class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int res=INT_MIN;
        int n=arr.size();
        vector<int> nsl(n);
        vector<int> ngr(n);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if(s.empty()) nsl[i]=-1;
            else nsl[i]=s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if(s.empty()) ngr[i]=n;
            else ngr[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<n;i++)
        {
            int ele=arr[i];
            int left=nsl[i];
            int right=ngr[i];
            res=max(res,arr[i]*(right-left-1));
            
        }
        return res;
    }
};