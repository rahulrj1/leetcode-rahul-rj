class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wt = 0.0;
        int eat = customers[0][0]; // earliest available time (eat)
        for(vector<int> &c: customers) {
            if(eat <= c[0]) wt += c[1], eat = c[0]+c[1];
            else wt += (c[1]+eat-c[0]), eat = eat+c[1]; 
        }
        double n = customers.size();
        return wt/n;
    }
};