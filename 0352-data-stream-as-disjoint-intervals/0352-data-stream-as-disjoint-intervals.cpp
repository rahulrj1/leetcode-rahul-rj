class SummaryRanges {
    set<int> s;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(int i: s) {
            if(!ans.empty() && ans.back()[1] == i-1) ans.back()[1] = i;
            else ans.push_back({i, i});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */