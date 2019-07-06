class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()) {
            while(!stack1.empty()) {
                int node = stack1.top();
                stack1.pop();
                stack2.push(node);
            }
        }
        if(stack2.empty()) {
            throw "queue is empty!";
        }
        int node = stack2.top();
        stack2.pop();
        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
