class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> inc(n, false), dec(n, false);
        inc[0] = true;
        for (int i = 1; i < n; ++i) {
            inc[i] = inc[i - 1] && nums[i] > nums[i - 1];
        }
    
        dec[n - 1] = true;
        for (int i = n - 2; i >= 0; --i) {
            dec[i] = dec[i + 1] && nums[i] > nums[i + 1];
        }

      
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        long long totalSum = prefixSum[n - 1];
        long long minDiff = LLONG_MAX;
        bool found = false;
        for (int i = 0; i < n - 1; ++i) {
            if (inc[i] && dec[i + 1]) {
                long long leftSum = prefixSum[i];
                long long rightSum = totalSum - leftSum;
                minDiff = min(minDiff, abs(leftSum - rightSum));
                found = true;
            }
        }

        return found ? minDiff : -1;
    }
};
