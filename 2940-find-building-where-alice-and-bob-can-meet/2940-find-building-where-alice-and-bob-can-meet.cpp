class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n, -1);
        vector<vector<int>> z;
        for(int i=0; i<n; i++) {
            if(queries[i][0] == queries[i][1]) 
                ans[i] = queries[i][0];
            else if ((queries[i][0] < queries[i][1]) && (heights[queries[i][0]] < heights[queries[i][1]]))
                ans[i] = queries[i][1];
            else if ((queries[i][0] > queries[i][1]) && (heights[queries[i][0]] > heights[queries[i][1]]))                     ans[i] = queries[i][0];
            else if(queries[i][0] > queries[i][1]) z.push_back ({queries[i][0], queries[i][1], i});
            else z.push_back ({queries[i][1], queries[i][0], i});
        }
        sort(z.rbegin(), z.rend());
        vector<int> st;
        int idx = heights.size() - 1; 
        for(int i=0; i<z.size(); i++) {
            // y = z[i][0], x = z[i][1], index = z[i][2]
            
            while(idx > z[i][0]) {
                // push heights[idx] into the monotonic stack
                while(!st.empty() && heights[st.back()] <= heights[idx]) st.pop_back();
                st.push_back(idx); idx--;
            }
            int l = 0, h = st.size()-1;
            while(l <= h) {
                int mid = l + (h-l)/2;
                if(heights[st[mid]] > heights[z[i][1]]) ans[z[i][2]] = st[mid], l = mid + 1; // original array me mid ke pehle
                else if(heights[st[mid]] <= heights[z[i][1]]) h = mid - 1;// original array me mid ke baad
            }
        }
        return ans;
    }
};