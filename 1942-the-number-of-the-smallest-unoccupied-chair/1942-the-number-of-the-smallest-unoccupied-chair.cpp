class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chair(n, -1); // ith person is sitting on which chair
        priority_queue<int, vector<int>, greater<int> > avChairs;
        for(int i=0; i<n; i++) avChairs.push(i);
        
        for(int i=0; i<n; i++) times[i].push_back(i);
        sort(times.begin(), times.end());
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sittingFolks;
        
        for(int i=0; i<n; i++) {
            // put all the empty chairs in pq
            int arrival = times[i][0];
            while(!sittingFolks.empty() && sittingFolks.top().first <= arrival) {
                int friendNo = sittingFolks.top().second;
                sittingFolks.pop();
                avChairs.push(chair[friendNo]);
            }
            
            // person sits on min chair
            int c = avChairs.top(); avChairs.pop();
            int friendNo = times[i][2];
            chair[friendNo] = c;
            if(friendNo == targetFriend) return c;
            sittingFolks.push(make_pair(times[i][1], friendNo));
        }
        return -1;
    }
};