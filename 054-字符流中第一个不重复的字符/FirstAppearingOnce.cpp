class Solution
{
public:
    // 定义 stringstream
    // char 可以存储 1 字节的整型数据，因为所有的字符不超过 256，因此字符出现的次数可以用 char 存储
    string s;
    char hashTable[256] = {0};
  //Insert one char from stringstream
    void Insert(char ch)
    {
        s += ch;
        // ascii 值即可当作下标
        hashTable[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i = 0; i < s.size(); i++) 
        {
            if(hashTable[s[i]] == 1)
                return s[i];
        }
        return '#';
    }

};
