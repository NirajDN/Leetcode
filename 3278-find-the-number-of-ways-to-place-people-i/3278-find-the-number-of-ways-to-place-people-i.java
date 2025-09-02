class Solution {
    public int numberOfPairs(int[][] points) {
        int maxi = 0;
        for(int i=0;i<points.length;i++)
        {
            for(int j=0;j<points.length;j++)
            {
                if(i==j || points[i][0]>points[j][0] || points[i][1]<points[j][1])
                {
                    continue;
                }
                int k = 0;
                for(;k<points.length;k++)
                {
                    if(k==i || k==j)
                    {
                        continue;
                    }
                    if(points[k][1] <= points[i][1] && points[k][1] >= points[j][1] && points[k][0] <= points[j][0] && points[k][0] >= points[i][0]) {
                        break;
                    }
                }
                if(k==points.length)
                {
                    maxi++;
                }
            }
        }
        return maxi;
    }
}
