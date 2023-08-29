class Solution {
public:
    int bestClosingTime(string customers) {
          int p=0;
          for(auto i:customers) if(i=='Y') p=p+1; 
          int mini = p, j = 0;
          for (int i = 0; i < customers.size(); ++i) {
            p += customers[i] == 'Y' ? -1 : 1;
            if (p < mini) {
                mini = p;
                j = i + 1;
            }
           }
        return j;
    }
};