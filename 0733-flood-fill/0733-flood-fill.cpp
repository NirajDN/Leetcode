class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size(); 
        int target = image[sr][sc];
        if (target == color) return image;  
        DFS(image, sr, sc, m, n, target, color);
        return image;
    }
    void DFS(vector<vector<int>>& image, int r, int c, int m, int n, int target, int newColor) {
        if (r < 0 || c < 0 || r >= m || c >= n || image[r][c] != target)
            return;

        image[r][c] = newColor;
        DFS(image, r + 1, c, m, n, target, newColor);
        DFS(image, r - 1, c, m, n, target, newColor);
        DFS(image, r, c + 1, m, n, target, newColor);
        DFS(image, r, c - 1, m, n, target, newColor);
    }
};
