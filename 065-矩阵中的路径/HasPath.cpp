class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
            return false;
        // 定义 bool 矩阵表示矩阵每个元素是否被访问过
        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);
        int pathLength = 0;
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
                    return true;
            }
        }
        delete [] visited;
        return false;
    }
    
    bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int & pathLength, bool* visited)
    {
        // 已经查询到字符串末尾，表示已经找到路径
        if(str[pathLength] == '\0')
            return true;
        bool hasPath = false;
        if(row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
        {
            pathLength++;
            visited[row * cols + col] = true;
            hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited) ||
                        hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) ||
                        hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) ||
                        hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
            // 当前元素找不到路径，退回上一元素
            if(!hasPath)
            {
                pathLength--;
                visited[row * cols + col] = false;
            }

        }
        return hasPath;
        
    }
};
