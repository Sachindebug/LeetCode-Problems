class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& arr) {
        int n=arr.size();
        if(n<=2) true;
        int x1=arr[1][0]-arr[0][0];
        int y1=arr[1][1]-arr[0][1];
        return recurse(arr,2,x1,y1);
    }
    bool recurse(vector<vector<int>>& arr,int idx,int x,int y)
    {
        if(idx==arr.size()) return true;
        int a=arr[idx-1][0];
        int b=arr[idx-1][1];
        int c=arr[idx][0];
        int d=arr[idx][1];
        int x1 = c-a;
        int y1 = d-b;
        if(x*y1!=y*x1) return false;
        return recurse(arr,idx+1,x,y);
    }
};