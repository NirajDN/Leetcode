class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
    int n = skill.size(), m = mana.size();
    vector<long long> done(n + 1);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i)
            done[i + 1] = max(done[i + 1], done[i]) + mana[j] * skill[i];
        for (int i = n - 1; i > 0; --i)
            done[i] = done[i + 1] - mana[j] * skill[i];     
    }
    return done.back();
}
};