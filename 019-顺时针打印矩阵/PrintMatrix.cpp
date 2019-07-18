class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> mat;
        int rows = matrix.size();
        int columns = matrix[0].size();
        if(rows <= 0 || columns <= 0) {
            return mat;
        }
        
        int start = 0;
        while(rows > 2 * start && columns > 2 * start) {
            vector<int> tmp = printMatrixInCircle(matrix, rows, columns, start);
            mat.insert(mat.end(), tmp.begin(), tmp.end());
            start++;
        }
        return mat;
    }

    vector<int> printMatrixInCircle(vector<vector<int> > & matrix, int rows, int columns, int start) {
        vector<int> mat;
        int endX = columns - 1 - start;
        int endY = rows - 1 - start;

        // 从左到右打印一行
        for(int i = start; i <= endX; i++) {
            mat.push_back(matrix[start][i]);
        }

        // 从上到下打印一列
        if(start < endY) {
            for(int i = start + 1; i <= endY; i++) {
                mat.push_back(matrix[i][endX]);
            }
        }

        // 从右到左打印一行
        if(start < endX && start < endY) {
            for(int i = endX - 1; i >= start; i--) {
                mat.push_back(matrix[endY][i]);
            }
        }

        // 从下到上打印一列
        if(start < endX && start < endY - 1) {
            for(int i = endY - 1; i > start; i--) {
                mat.push_back(matrix[i][start]);
            }
        }
        
        return mat;
    }
};
