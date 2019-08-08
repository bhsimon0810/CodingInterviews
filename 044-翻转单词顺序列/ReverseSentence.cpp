class Solution {
public:
    string ReverseSentence(string str) {
        if(str.size() <= 1) return str;
        reverse(str.begin(), str.end());
        int front = 0, rear = 0, size = str.size();
        while(front < size && rear < size) {
            while(front < size && str[front] == ' ') front++;
            rear = front;
            while(rear < size && str[rear] != ' ') rear++;
            reverse(str.begin() + front, str.begin() + rear);
            front = rear;
        }
        return str;
    }
};
