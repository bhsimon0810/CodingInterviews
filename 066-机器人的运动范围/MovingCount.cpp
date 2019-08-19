class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0 || rows < 1 || cols < 1)
            return 0;
        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);
        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
        delete [] visited;
        return count;
    }

    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        int count = 0;
        if(check(threshold, rows, cols, row, col, visited))
        {
            visited[row * cols + col] = true;
            count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
                      + movingCountCore(threshold, rows, cols, row + 1, col, visited)
                      + movingCountCore(threshold, rows, cols, row, col - 1, visited)
                      + movingCountCore(threshold, rows, cols, row, col + 1, visited);
        }
        return count;
    }

    bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        if(row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row, col) <= threshold && !visited[row * cols + col])
            return true;
        else
            return false;
    }

    int getDigitSum(int row, int col)
    {
        int sum = 0;
        while(row > 0 || col > 0)
        {
            sum += row % 10;
            sum += col % 10;
            row /= 10;
            col /= 10;
        }
        return sum;
    }
};
