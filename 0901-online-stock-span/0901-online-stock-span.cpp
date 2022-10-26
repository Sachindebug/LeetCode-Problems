class StockSpanner {
    stack<int> s;
    vector<int> p;
    int i=0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
       int res=0;
       p.push_back(price);
       while(!s.empty() && p[s.top()]<=price)
       {
           s.pop();
       }
       if(s.empty()) res=i+1;
       else
       {
           res=i-s.top();
       }
       s.push(i);
       i++;
       
       return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */