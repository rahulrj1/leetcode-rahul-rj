class Solution {
public:
    int findParent(int node, vector<int> &parenta, vector<int> &parentb) {
        if(parenta[node] == node) return node;
        parenta[node] = findParent(parenta[node], parenta, parentb);
        return parentb[node] = parenta[node];
    }
    
    int findParent(int node, vector<int> &parent) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent);
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parenta(n+1);
        vector<int> parentb(n+1);
        for(int i=0; i<n; i++) parenta[i] = i, parentb[i] = i;
        
        int res = 0;
        for(vector<int> edge: edges) {
            if(edge[0] == 3) {
                int pa = findParent(edge[1], parenta, parentb);
                int pb = findParent(edge[2], parenta, parentb);
                
                if(pa != pb) {
                    parenta[pa] = pb;
                    parentb[pa] = pb;
                    res++;
                }
            }
        }
        
        for(vector<int> edge: edges) {
            if(edge[0] == 1) {
                int pa = findParent(edge[1], parenta);
                int pb = findParent(edge[2], parenta);
                
                if(pa != pb) {
                    parenta[pa] = pb;
                    res++;
                }
            }
            else if(edge[0] == 2) {
                int pa = findParent(edge[1], parentb);
                int pb = findParent(edge[2], parentb);
                
                if(pa != pb) {
                    parentb[pa] = pb;
                    res++;
                }
            }
        }
        res = edges.size() - res;
        int roota = findParent(1, parenta), rootb = findParent(1, parentb);
        for(int i=2; i<=n; i++) {
            int pa = findParent(i, parenta);
            if(pa != roota) {res = -1; break;}
            int pb = findParent(i, parentb);
            if(pb != rootb) {res = -1; break;}
        }
        return res;
    }
};