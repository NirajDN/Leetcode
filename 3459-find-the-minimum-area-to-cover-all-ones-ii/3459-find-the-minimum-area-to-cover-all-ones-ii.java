class Solution {
    int[][] grid;
    int n, m;
    public int minimumSum(int[][] grid) {
        this.grid = grid;
        n = grid.length;
        m = grid[0].length;
        
        int ans = Integer.MAX_VALUE/3;
        
        // horizontal slice
        for(int i = 0;i<n-1;i++) {
            ans = Math.min(ans, Math.min(oneRectMaxArea(0,0,i,m-1) + twoRectMaxArea(i+1,0, n-1, m-1),
                                        twoRectMaxArea(0,0,i,m-1) + oneRectMaxArea(i+1,0, n-1, m-1)));
        }
        
        // vertical slice
        for(int j = 0;j<m-1;j++) {
            ans = Math.min(ans, Math.min(oneRectMaxArea(0, 0, n-1, j) + twoRectMaxArea(0, j+1, n-1, m-1),
                                        twoRectMaxArea(0, 0, n-1, j) + oneRectMaxArea(0, j+1, n-1, m-1)));
        }
        
        return ans;
    }
    
    public int twoRectMaxArea(int x, int y, int p, int q) {
        // horizontal slice
        int ans = Integer.MAX_VALUE/2;
        for(int i = x;i<p;i++) {
            ans = Math.min(ans, oneRectMaxArea(x,y,i,q) + oneRectMaxArea(i+1,y,p,q));
        }
        
        // vertical slice
        for(int j = y;j<q;j++) {
            ans = Math.min(ans, oneRectMaxArea(x,y,p,j) + oneRectMaxArea(x,j+1,p,q));
        }
        
        return ans;
    } 
    
    public int oneRectMaxArea(int x, int y, int p, int q) {
        int mih = q, mah = y, miv = p, mav = x;
        boolean has = false;
        
        for(int i = x;i<=p;i++) {
            for(int j = y;j<=q;j++) {
                if (grid[i][j] == 0) continue;
                has = true;
                mih = Math.min(mih, j);
                mah = Math.max(mah, j);
                
                miv = Math.min(miv, i);
                mav = Math.max(mav, i);
            }
        }
        
        return !has ? Integer.MAX_VALUE/4 : (mah - mih + 1)*(mav - miv + 1);
    }
}