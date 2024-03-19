class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans, m = 0;
        vector<int> freq(26, 0);
        for(char c: tasks) freq[c-'A']++, m = max(m, freq[c-'A']);
        ans = (m-1)*(n+1);
        for(int f: freq) if(f == m) ans++;
        return max((int)tasks.size(), ans);
    }
};