class Solution {
private:
    int countValidCuts(vector<int> &start, vector<int> &end){
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int count = 0;
        int valid = 0;
        int n = start.size();
        int i = 0,j = 0;
        while(j<n && i<n){
            if(start[i]<end[j]) {
                count++;
                i++;
            }
            else {
                count--;
                j++;
            }
            if(count==0) valid++;
        }
        return valid;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<int> hstart,hend,vstart,vend;
        for(auto rectangle: rectangles){
            hstart.push_back(rectangle[0]);
            hend.push_back(rectangle[2]);
            vstart.push_back(rectangle[1]);
            vend.push_back(rectangle[3]);
        }
        int count1 = countValidCuts(hstart,hend);
        int count2 = countValidCuts(vstart,vend);
        return count1>=2 || count2>=2;
    }
};