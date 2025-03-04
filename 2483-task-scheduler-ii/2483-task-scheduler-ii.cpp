class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day = 0;
        map<int,long long> last;
        for(auto x:tasks){
            if(last.find(x)==last.end()){
                day++;
                last[x] = day;
            }
            else{
                long long prev = last[x];
                if(day-prev>space){
                    day++;
                    last[x] = day;
                }
                else{
                    int diff = day-prev;
                    diff = space-diff;
                    day+=diff+1;
                    last[x] = day;
                }
            }
        }
        return day;
    }
};