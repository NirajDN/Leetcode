class Solution {
public:
        double memo[200][200];
    double soupServings(int N) {
        return N > 4800 ?  1.0 : f((N + 24) / 25, (N + 24) / 25);
    }
    double f(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;
        if (memo[a][b] > 0) return memo[a][b];
        memo[a][b] = 0.25 * (f(a-4,b)+f(a-3,b-1)+f(a-2,b-2)+f(a-1,b-3));
        return memo[a][b];
    }
};