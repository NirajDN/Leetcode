class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int mod = 1e9 + 7;
        int n = board.size();

        vector<vector<int>> maxScore(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        maxScore[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(board[i][j] == 'X'){
                    continue;
                }

                if(i == n - 1 && j == n - 1){
                    continue;
                }

                int bestScore = -1;
                long long totalWays = 0;

                if(i + 1 < n && maxScore[i + 1][j] != -1){
                    if(maxScore[i + 1][j] > bestScore){
                        bestScore = maxScore[i + 1][j];
                        totalWays = ways[i + 1][j];
                    }else if(maxScore[i + 1][j] == bestScore){
                        totalWays = (totalWays + ways[i + 1][j]) % mod;
                    }
                }

                if(j + 1 < n && maxScore[i][j + 1] != -1){
                    if(maxScore[i][j + 1] > bestScore){
                        bestScore = maxScore[i][j + 1];
                        totalWays = ways[i][j + 1];
                    }else if(maxScore[i][j + 1] == bestScore){
                        totalWays = (totalWays + ways[i][j + 1]) % mod;
                    }
                }

                if(i + 1 < n && j + 1 < n && maxScore[i + 1][j + 1] != -1){
                    if(maxScore[i + 1][j + 1] > bestScore){
                        bestScore = maxScore[i + 1][j + 1];
                        totalWays = ways[i + 1][j + 1];
                    }else if(maxScore[i + 1][j + 1] == bestScore){
                        totalWays = (totalWays + ways[i + 1][j + 1]) % mod;
                    }
                }

                if(bestScore == -1){
                    continue;
                }

                int curr = 0;
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    curr = board[i][j] - '0';
                }

                maxScore[i][j] = bestScore + curr;
                ways[i][j] = totalWays % mod;
            }
        }

        if(maxScore[0][0] == -1){
            return {0, 0};
        }

        return {maxScore[0][0], ways[0][0]};
    }
};