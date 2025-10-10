class Solution {
public:
    char kthCharacter(int k) {
        k--;
        int count = 0;
        while (k > 0) {
            count += (k & 1);
            k /= 2;
        }
        return (char)('a' + (count % 26));
    }
};