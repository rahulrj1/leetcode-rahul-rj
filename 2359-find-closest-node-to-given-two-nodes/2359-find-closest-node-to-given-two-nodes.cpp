class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dis1(edges.size(), 1e6);
        vector<int> dis2(edges.size(), 1e6);
        
        int dis = 0;
        while(node1 != -1 && dis1[node1] > dis) {
            dis1[node1] = dis++;
            node1 = edges[node1];
        }
        
        dis = 0;
        while(node2 != -1 && dis2[node2] > dis) {
            dis2[node2] = dis++;
            node2 = edges[node2];
        }
        
        int minDis = 1e6, ans = -1;
        for(int i=0; i<edges.size(); i++) {
            // cout<<dis1[i]<<" "<<dis2[i]<<"  ";
            int z = max(dis1[i], dis2[i]);
            if(minDis > z) minDis = z, ans = i;
        }
        
        // cout<<minDis;
        return ans;
    }
};