class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size(); 
        vector<int> result;
        int u = 0, d = row - 1, l = 0, r = column - 1;
        while (result.size() < row * column) {
            for (int j = l; j <= r; j++) {
                if (result.size() < row * column) {
                    result.push_back(matrix[u][j]);    
                }
                else break;
            }
            for (int i = u + 1; i <= d - 1; i++) {
                if (result.size() < row * column) {
                    result.push_back(matrix[i][r]);                    
                }
                else break;
            }
            
            for (int j = r; j >= l; j--) {
                if (result.size() < row * column) {
                   result.push_back(matrix[d][j]); 
                }
                else break;
            }
            for (int i = d - 1; i >= u + 1; i--) 
                if (result.size() < row * column) {
                    result.push_back(matrix[i][l]);    
                }
                else break;
            
            l++; r--; u++; d--; 
        }
        return result;
    }
};