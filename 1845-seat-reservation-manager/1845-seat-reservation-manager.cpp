class SeatManager {
public:
    set<int> available;
    SeatManager(int n) {
        for(int i=1;i<=n;i++) available.insert(i);
    }
    
    int reserve() {
        int x = *available.begin();
        available.erase(available.begin());
        return x;
    }
    
    void unreserve(int seatNumber) {
        available.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */