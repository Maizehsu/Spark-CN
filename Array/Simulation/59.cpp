class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int val = 1, size = n * n, up = 0, down = n - 1, left = 0, right = n - 1;
        while (val <= size) {
            for (int j = left; j <= right; j++) {
                if (val <= size) res[up][j] = val++;
                else break;
            }
            for (int i = up + 1; i <= down - 1; i++) {
                if (val <= size) res[i][right] = val++;
                else break;
            }
            for (int j = right; j >= left; j--) {
                if (val <= size) res[down][j] = val++;
                else break;
            }
            for (int i = down - 1; i >= up + 1; i--) {
                if (val <= size) res[i][left] = val++;
                else break;
            }
            up++; down--; left++; right--;
        }
        return res;
    }
};