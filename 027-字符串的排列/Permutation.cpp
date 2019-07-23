class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> strlist;
        if(str.empty()) return strlist;
        Permutation(strlist, str, 0);
        sort(strlist.begin(), strlist.end());
        return strlist;
    }
    
    void Permutation(vector<string> & strlist, string str, int begin) {
        if(begin == str.size() - 1) {
            if(find(strlist.begin(), strlist.end(), str) == strlist.end()) {
                strlist.push_back(str);
            }
        }
        else {
            for(int i = begin; i < str.size(); i++) {
                swap(str[begin], str[i]);
                Permutation(strlist, str, begin + 1);
                swap(str[begin], str[i]);
            }
        }
    }
    
    void swap(char & ch1, char & ch2) {
        char tmp = ch1;
        ch1 = ch2;
        ch2 = tmp;
    }
};
