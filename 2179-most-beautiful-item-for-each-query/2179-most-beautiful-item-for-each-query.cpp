class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<int> res;
        vector<pair<int,int>> mxele;
        int mx = INT_MIN;
        for(auto x:items){
            if(x[1]>mx) mx = x[1];
            mxele.push_back({x[0],mx});
        }
        for(auto x: queries){
            int idx = binarySearch(mxele,x);
            if(idx!=-1) res.push_back(mxele[idx].second);
            else res.push_back(0);
        }
        return res;
    }
    int binarySearch(vector<pair<int,int>> &arr, int x){
        int l = 0;
        int r = arr.size()-1;
        int ans = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            int ele = arr[m].first;
            if(ele>x){
                r = m-1;
            }
            else
            {
                ans = m;
                l = m+1;
            }
        }
        return ans;
    }
};