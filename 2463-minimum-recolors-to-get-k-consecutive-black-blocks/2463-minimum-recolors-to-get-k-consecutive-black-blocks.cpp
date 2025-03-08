class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        int mn = INT_MAX;
        for(int i = 0;i<k;i++){
            if(blocks[i]=='W') count++;
        }
        mn = min(mn,count);
        for(int i = k;i<blocks.size();i++){
            count+=blocks[i]=='W';
            count-=blocks[i-k]=='W';
            mn = min(mn,count);
        }
        return mn;
    }
};