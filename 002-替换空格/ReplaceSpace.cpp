class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str == NULL || length <= 0)
            return;
        int originalLength = 0;
        int numberOfSpace = 0;
        
        int i = 0;
        while(str[i] != '\0') {
            originalLength++;
            if(str[i] == ' ') {
                numberOfSpace++;
            }
            i++;
        }

        int newLength = originalLength + 2 * numberOfSpace;
        if(newLength > length) return;

        int p1 = originalLength, p2 = newLength;
        while(p1 < p2 && p1 >= 0) {
            if(str[p1] == ' ') {
                str[p2--] = '0';
                str[p2--] = '2';
                str[p2--] = '%';
            }
            else {
                str[p2--] = str[p1];
            }
            p1--;
        }
    }
};
