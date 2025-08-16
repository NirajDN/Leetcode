class Solution {
public:
    int maximum69Number (int num) {
        int i{1000};
        while(i != 0 && (num / i) % 10 != 6)
            i /= 10;
        return num + 3*i;
    }
};