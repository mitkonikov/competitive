class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int k = 0;
        while (num2 > 0) {
            k += num2 & 1;
            num2 >>= 1;
        }
        int x = 0;
        for (int i = 30; k > 0 && i >= 0; i--) {
            if (num1 & (1 << i)) {
                x |= (1 << i);
                k--;
            }
        }
        if (k) {
            for (int i = 0; k > 0 && i <= 30; i++) {
                if (!((x & (1 << i)) > 0)) {
                    x |= (1 << i);
                    k--;
                }
            }
        }
        return x;
    }
};