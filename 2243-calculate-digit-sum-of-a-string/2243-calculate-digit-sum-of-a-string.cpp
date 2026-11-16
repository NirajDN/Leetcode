class Solution {
public:
    string digitSum(string s, int k) {
        while (ssize(s) > k) {
            string next;
            for (int i = 0; i < ssize(s); i += k) {
                string_view group = string_view(s).substr(i, k);
                next += to_string(accumulate(group.begin(), group.end(), 0, [](int sum, char d) { return sum + d - '0'; }));
            }
            s = next;
        }
        return s;
    }
};