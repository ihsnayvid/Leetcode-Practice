class MyCalendarTwo {
public:
    vector<pair<int, int>> vp, vp2;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        for(auto i: vp2){
            if(i.first < end and i.second > start) return false;
        }
        
        for(auto i: vp){
            if(i.first < end and i.second > start){
                vp2.push_back({max(start, i.first), min(end, i.second)});
            }
        }
        vp.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */