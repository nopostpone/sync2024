class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.length();
        vector<int> f(size, 0);
        int maxVal = 0;
        for (int i = 1; i < size; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    f[i] = 2;
                    if (i - 2 >= 0) {
                        f[i] = f[i] + f[i - 2];
                    }
                } else if (f[i - 1] > 0) {
                    if ((i - f[i - 1] - 1) >= 0 && s[i - f[i - 1] - 1] == '(') {
                        f[i] = f[i - 1] + 2;
                        if ((i - f[i - 1] - 2) >= 0) {
                            f[i] = f[i] + f[i - f[i - 1] - 2];
                        }
                    }
                }
            }
            maxVal = max(maxVal, f[i]);
        }
        return maxVal;
    }
};
