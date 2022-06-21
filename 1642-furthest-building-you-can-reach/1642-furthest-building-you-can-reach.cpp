class Solution {
public:
    int furthestBuilding(vector<int>& arr, int b, int l) {
       priority_queue<int, vector<int>, greater<int> > pq; 
       int n=arr.size();
       int sum=0;
       for(int i=0;i<n-1;i++)
       {
           if(arr[i+1]>arr[i])
           {
               pq.push(arr[i+1]-arr[i]);
               if(pq.size()>l)
               {
                   sum+=pq.top();
                   pq.pop();
               }
               if(sum>b) return i;
           }
       }
       return n-1;
    }
};