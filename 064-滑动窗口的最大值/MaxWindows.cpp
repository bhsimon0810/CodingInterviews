class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> maxNumbers;
        // 双端队列保存的是元素下标值
        deque<int> q;
        for(unsigned int i = 0; i < num.size(); i++)
        {
            // 依次弹出队列中比当前num小的元素，保证队首元素始终为窗口范围内的最大值
            while(!q.empty() && num[q.back()] < num[i])
                q.pop_back();
            // 保证队列中的元素不超过窗口范围
            while(!q.empty() && i - q.front() + 1 > size)
                q.pop_front();
            q.push_back(i);
            // 队列中元素个数达到窗口范围开始输出
            if(size != 0 && i + 1 >= size)
                maxNumbers.push_back(num[q.front()]);
        }
        return maxNumbers;
    }
};
