class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int x=tops[0];
        int y=bottoms[0];
        int n=tops.size();
        bool xf=true;
        bool yf=true;
        for(int i=0;i<n;i++)
        {
            if(tops[i]!=x && bottoms[i]!=x) xf=false;
        }
        for(int i=0;i<n;i++)
        {
            if(tops[i]!=y && bottoms[i]!=y) yf=false;
        }
        if(!xf && !yf) return -1;
        int arrx[7]={0};
        int arry[7]={0};
        for(int i=0;i<n;i++)
        {
            arrx[tops[i]]++;
            arry[bottoms[i]]++;
        }
        int res1=INT_MIN;
        int res2=INT_MIN;
        for(int i=0;i<7;i++)
        {
           res1=max(res1,arrx[i]);
           res2=max(res2,arry[i]); 
        }
        return min(n-res1,n-res2);


        

    }
};