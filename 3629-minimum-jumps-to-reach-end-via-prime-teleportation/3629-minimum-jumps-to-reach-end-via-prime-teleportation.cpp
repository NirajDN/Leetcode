class Solution {
public:
    static constexpr int MAXV = 1'000'001;

    // smallest prime factor sieve
    static const vector<int>& getSPF() {

        static const vector<int> spf = [](){
            vector<int> s(MAXV);
            for(int i = 0; i < MAXV; i++){
                s[i] = i;
            }

            s[0] = 0;
            s[1] = 1;
            for(long long i = 2; i * i < MAXV; i++){
                if(s[i] == i){

                    for(long long j = i * i; j < MAXV; j += i){
                        if(s[j] == j){
                            s[j] = i;
                        }
                    }
                }
            }
            return s;
        }();
        return spf;
    }

    bool isPrime(int x, const vector<int>& spf){

        return x >= 2 && spf[x] == x;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return 0;

        const auto& spf = getSPF();

        int maxi = *max_element(nums.begin(), nums.end());

        // store which prime numbers are present in nums
        vector<char> primeSeen(maxi + 1, false);

        for(int x : nums){

            if(isPrime(x, spf)){
                primeSeen[x] = true;
            }
        }

        // prime -> indices divisible by that prime
        unordered_map<int, vector<int>> mp;
        mp.reserve(n * 2);

        for(int i = 0; i < n; i++){

            int x = nums[i];

            if(x == 1) continue;

            while(x > 1){

                int p = spf[x];

                // only store useful primes
                if(p <= maxi && primeSeen[p]){
                    mp[p].push_back(i);
                }

                // remove duplicate prime factors
                while(x % p == 0){
                    x /= p;
                }
            }
        }

        vector<int> dist(n, -1);

        // to avoid reusing same teleportation
        vector<char> usedPrime(maxi + 1, false);

        queue<int> q;

        q.push(0);
        dist[0] = 0;

        while(!q.empty()){

            int idx = q.front();
            q.pop();

            if(idx == n - 1){
                return dist[idx];
            }

            // left move
            if(idx - 1 >= 0 && dist[idx - 1] == -1){

                dist[idx - 1] = dist[idx] + 1;
                q.push(idx - 1);
            }

            // right move
            if(idx + 1 < n && dist[idx + 1] == -1){
                dist[idx + 1] = dist[idx] + 1;
                q.push(idx + 1);
            }

            int x = nums[idx];
            // teleportation
            if(x <= maxi && isPrime(x, spf) && !usedPrime[x]){
                usedPrime[x] = true;
                auto it = mp.find(x);
                if(it != mp.end()){

                    for(int nextIdx : it->second){
                        if(dist[nextIdx] == -1){

                            dist[nextIdx] = dist[idx] + 1;
                            q.push(nextIdx);
                        }
                    }
                }
            }
        }

        return -1;
    }
};