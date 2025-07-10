class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        stack<char> st;

        for (char c : s)
            count[c - 'a']++;

        for (char c : s) {
            count[c - 'a']--;

            if (visited[c - 'a']) continue;

            while (!st.empty() && c < st.top() && count[st.top() - 'a'] > 0) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            visited[c - 'a'] = true;
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
