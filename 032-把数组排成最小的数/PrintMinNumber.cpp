class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.size() <= 0) return "";
        string ans = "";
        sort(numbers.begin(), numbers.end(), compare);
        for(int i = 0; i < numbers.size(); i++) {
            ans += to_string(numbers[i]);
        }
        return ans;
    }
    
    static bool compare(int a, int b) {
        string sa = "";
        string sb = "";
        sa += to_string(a);
        sa += to_string(b);
        sb += to_string(b);
        sb += to_string(a);
        return sa < sb;
    }
};
