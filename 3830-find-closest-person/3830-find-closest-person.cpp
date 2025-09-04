class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(x - z), b = abs(y - z);
        return (a != b) << (a > b);
    }
};