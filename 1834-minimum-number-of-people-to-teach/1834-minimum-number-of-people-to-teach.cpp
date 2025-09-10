// use unordered_set for comparison
class Solution {
public:
    static bool intersection(unordered_set<int>& X, unordered_set<int>& Y){
        if (X.size()>Y.size()) return intersection(Y, X);
        for(int x: X){
            if (Y.count(x)) return 1;
        }
        return 0;
    }
    static int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size(); // number of people

        // store known languages for each person
        vector<unordered_set<int>> know(m);
        for (int i=0; i<m; i++) 
            for (int l : languages[i]) know[i].insert(l);
        

        // people need be taught
        unordered_set<int> need;
        need.reserve(500);
        for (auto& f : friendships) {
            int a=f[0]-1, b=f[1]-1;
            if (intersection(know[a],know[b])) continue; // can talk
            need.insert(a);
            need.insert(b);
        }

        // if no need
        if (need.size()==0) return 0;

        int ans=INT_MAX;
        for (int lang=1; lang<=n; lang++) {   // languages for 1..n
            int cnt=0;
            for (int i: need) {
                if (!know[i].count(lang)) cnt++;
            }
            ans=min(ans, cnt);
        }

        return ans;
    }
};