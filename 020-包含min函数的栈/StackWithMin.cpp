class Solution {
public:

    stack<int> s_data, s_min;

    void push(int value) {
        s_data.push(value);
        if(s_min.size() == 0 || value <= s_min.top()) {
            s_min.push(value);
        }
    }
    void pop() {
        if(s_data.top() == s_min.top()) {
            s_min.pop();
        }
        s_data.pop();
    }
    int top() {
        return s_data.top();
    }
    int min() {
        return s_min.top();
    }
};
