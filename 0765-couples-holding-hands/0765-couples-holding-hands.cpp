class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        if(row.size() <=2){
            return 0;
        }
        
        vector<int> pos(row.size());
        for(size_t i = 0; i< row.size(); i++){
            pos[row[i]] = i;
        }
        
        int count = 0;
        for(size_t i = 0; i < row.size(); i+=2){
            int &me = row[i];
            int myCouple = (me ^ 1);
            if(row[i+1] != myCouple){
                count++;
                int neighbor = row[i+1];
                row[pos[myCouple]] = neighbor;
                pos[neighbor] = pos[myCouple];
            }
        }
        
        return count;
    }
};