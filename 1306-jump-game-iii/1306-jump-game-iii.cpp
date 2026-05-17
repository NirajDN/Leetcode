class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i < 0 || i >= n || visited[i])
                continue;

            if (arr[i] == 0)
                return true;

            visited[i] = true;

            q.push(i + arr[i]);
            q.push(i - arr[i]);
        }

        return false;
    }
};