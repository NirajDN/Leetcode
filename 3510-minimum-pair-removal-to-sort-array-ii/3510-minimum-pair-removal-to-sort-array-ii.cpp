class Solution {
public:
    using ll = long long;

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return 0;

        vector<ll> arr(nums.begin(), nums.end());
        vector<bool> removed(n, false);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

        int sorted = 0;
        for (int i = 1; i < n; ++i) {
            pq.emplace(arr[i - 1] + arr[i], i - 1);
            if (arr[i] >= arr[i - 1])
                sorted++;
        }
        if (sorted == n - 1)
            return 0;

        int rem = n;
        vector<int> prev(n), next(n);
        for (int i = 0; i < n; ++i) {
            prev[i] = i - 1;
            next[i] = i + 1;
        }

        while (rem > 1) {
            auto [sum, left] = pq.top();
            pq.pop();
            int right = next[left];
            if (right >= n || removed[left] || removed[right] ||
                arr[left] + arr[right] != sum)
                continue;

            int pre = prev[left];
            int nxt = next[right];

            if (arr[left] <= arr[right])
                sorted--;
            if (pre != -1 && arr[pre] <= arr[left])
                sorted--;
            if (nxt != n && arr[right] <= arr[nxt])
                sorted--;

            arr[left] += arr[right];
            removed[right] = true;
            rem--;

            if (pre == -1) {
                prev[left] = -1;
            } else {
                pq.emplace(arr[pre] + arr[left], pre);
                if (arr[pre] <= arr[left])
                    sorted++;
            }

            if (nxt == n) {
                next[left] = n;
            } else {
                prev[nxt] = left;
                next[left] = nxt;
                pq.emplace(arr[left] + arr[nxt], left);
                if (arr[left] <= arr[nxt])
                    sorted++;
            }

            if (sorted == rem - 1)
                return n - rem;
        }
        return n;
    }
};
