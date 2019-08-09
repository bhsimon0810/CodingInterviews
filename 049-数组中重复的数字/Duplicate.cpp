class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        bool *k = new bool[length];
        for(int i = 0; i < length; i++) k[i] = false;
        for(int i = 0; i < length; i++) {
            if(k[numbers[i]] == true) {
                *duplication = numbers[i];
                return true;
            }
            k[numbers[i]] = true;
        }
        return false;
        
    }
};
