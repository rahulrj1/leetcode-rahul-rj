vector<long long> z1(20001);
vector<long long> z2(20001);

class Solution {
public:
    long long helper(int node, vector<int>& nums, int k, vector<vector<int>>& adjlist, int parent, bool isEdgeChanged) {
        if(isEdgeChanged && z2[node] != -1) return z2[node];
        if(!isEdgeChanged && z1[node] != -1) return z1[node];
        vector<long long> diff;
        long long z1Sum = 0LL;
        for(int child: adjlist[node]) {
            if(child == parent) continue;
            z1[child] = helper(child, nums, k, adjlist, node, false);
            z2[child] = helper(child, nums, k, adjlist, node, true);
            diff.push_back(z2[child]-z1[child]);
            z1Sum += z1[child];
        }
        
        // handle case when node is leaf node
        if(diff.size() == 0) {
            return isEdgeChanged ? (nums[node]^k) : nums[node];
        }
        
        sort(diff.rbegin(), diff.rend());
        long long finalOddDiff = diff[0], finalEvenDiff = 0;
        for(int i=2; i<diff.size(); i += 2) {
            if(diff[i]+diff[i-1] > 0) finalOddDiff += (diff[i]+diff[i-1]);
            else break;
        }
        for(int i=1; i<diff.size(); i += 2) {
            if(diff[i]+diff[i-1] > 0) finalEvenDiff += (diff[i]+diff[i-1]);
            else break;
        }
        
        // even child change
        long long evenRes = isEdgeChanged ? ((nums[node]^k) + z1Sum + finalEvenDiff) : (nums[node] + z1Sum + finalEvenDiff);
        
        // odd child change
        long long oddRes = isEdgeChanged ? (nums[node] + z1Sum + finalOddDiff) : ((nums[node]^k) + z1Sum + finalOddDiff);
        
        return max(evenRes, oddRes);
        
    }
    
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        fill(z1.begin(), z1.end(), -1);
        fill(z2.begin(), z2.end(), -1);
        vector<vector<int> > adjlist(nums.size());
        for(vector<int> &edge: edges) {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        return helper(0, nums, k, adjlist, -1, false);
    }
};