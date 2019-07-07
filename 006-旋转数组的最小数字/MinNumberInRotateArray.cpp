class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() <= 0) {
            throw "invalid parameters!";
        }
        int low = 0, high = rotateArray.size() - 1;
        int mid = low;
        while(rotateArray[low] >= ratateArray[high]) {
            if(high - low == 1) {
                return rotateArray[high];
            }

            mid = low + (high - low) / 2;
            if(rotateArray[low] == rotateArray[high] && rotateArray[low] == rotateArray[mid]) {
                return minNumberInOrder(rotateArray, low, high);
            }
            else if(rotateArray[mid] >= rotateArray[low]) {
                low = mid;
            }
            else if(rotateArray[mid] <= rotateArray[high]) {
                high = mid;
            }
        }
        return rotateArray[mid];
    }

    int minNumberInOrder(vector<int> & Array, int low, int high) {
        int minNumber = Array[low];
        for(int i = low + 1; i <= high; i++) {
            if(minNumber > Array[i]) {
                minNumber = Array[i];
            }
        }
        return minNumber;
    }
};
