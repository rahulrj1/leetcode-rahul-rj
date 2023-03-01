class Solution {
public:
    void mergeTheArray(vector<int> &nums, int st, int mid, int ed) {
        int n = ed - st + 1;
        vector<int> arr(n);
        int i=st, j=mid+1, k=0;
        while(i<=mid && j<=ed) {
            if(nums[i] <= nums[j]) arr[k++] = nums[i++];
            else arr[k++] = nums[j++];
        }
        while(i<=mid) arr[k++] = nums[i++];
        while(j<=ed) arr[k++] = nums[j++];
        for(int i=0; i<n; i++) nums[st+i] = arr[i];
    }
    
    void sortTheArray(vector<int> &nums, int st, int ed) {
        if(st >= ed) return;
        int mid = (st+ed)/2;
        sortTheArray(nums, st, mid);
        sortTheArray(nums, mid+1, ed);
        mergeTheArray(nums, st, mid, ed);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        sortTheArray(nums, 0, nums.size()-1);
        return nums;
    }
};