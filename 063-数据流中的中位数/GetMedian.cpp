class Solution {
    // 大顶堆用来存放较小数值的部分
    priority_queue<int, vector<int>, less<int> > p;
    // 小顶堆用来存放较大数值的部分
    priority_queue<int, vector<int>, greater<int> > q;
    // 这样保证大顶堆和小顶堆的 size 一致，则中位数就是堆顶元素的平均值
public:
    void Insert(int num)
    {
        if(p.empty() || num < p.top())
            p.push(num);
        else
            q.push(num);
        if(p.size() == q.size() + 2)
        {
            q.push(p.top());
            p.pop();
        }
        if(p.size() + 1 == q.size())
        {
            p.push(q.top());
            q.pop();
        }
    }

    double GetMedian()
    { 
        // 大顶堆长度要么与小顶堆相等（数据为偶数个），要么指挥比小顶堆多一（数据为奇数个）
        return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
    }

};
