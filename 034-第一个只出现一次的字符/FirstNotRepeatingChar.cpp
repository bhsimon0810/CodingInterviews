class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str) {
            unsigned int hashTable[58] = {0};
            for(int i = 0; i < str.size(); i++) {
                hashTable[str[i]- 65] += 1;
            }

            for(int i = 0; i < str.size(); i++) {
                if(hashTable[str[i]- 65] == 1) 
            }
        }
        return -1;
    }
};
