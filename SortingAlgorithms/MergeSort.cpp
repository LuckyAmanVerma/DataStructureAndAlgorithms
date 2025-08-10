/*
Merge Sort
Time Complexity: O(n log n) in all cases (worst, average, best).
Space Complexity: O(n) due to the need for temporary arrays during merging.
*/

// कब Merge Sort का इस्तेमाल करें (When to use Merge Sort):
// - जब आपको stable sort चाहिए (जैसे कि objects की sorting जिसमें order important है)
// - जब worst-case time complexity O(n log n) चाहिए (Heap/Quick sort worst-case में slow हो सकते हैं)
// - जब linked list को sort करना हो (merge sort in-place और efficient है)
// - जब input बहुत बड़ा है और external sorting (disk पर) करनी हो
//
// कब Merge Sort worst choice है:
// - जब memory constraint है (क्योंकि merge sort को O(n) extra space चाहिए)
// - जब array बहुत छोटा है (Insertion sort या Tim sort ज़्यादा efficient होते हैं)
// - जब in-place sorting चाहिए (merge sort array के लिए in-place नहीं है)

// Global variable to store inversion count
int inversionCount = 0;

void divide(vector<int> &array,int start,int end){
    if(start<end){
        int mid = start+(end-start)/2;
        divide(array,start,mid);
        divide(array,mid+1,end);
        mergeSort(array,start,mid,end);
    }
}


/*
   Optimized solution for counting inversions using merge sort:
   When array[i] > array[j] (i <= mid < j), all elements from i to mid are greater than array[j].
   So, increment inversionCount by (mid - i + 1).
*/
void mergeSort(vector<int> &array,int start,int mid,int end) {
    int i=start;
    int j=mid+1;
    vector<int> result;
    while(i<=mid && j<=end) {
        if(array[i]<=array[j]){
            result.push_back(array[i]);
            i+=1;
        }
        else{
            result.push_back(array[j]);
            // Count inversions here
            inversionCount += (mid - i + 1); // All elements from i to mid are greater than array[j]
            j+=1;
        }
    }
    while(i<=mid){
        result.push_back(array[i]);
        i++;
    }
    while(j<=end){
        result.push_back(array[j]);
        j++;
    }
    for(int k=0; k<result.size(); k++) array[start + k] = result[k];
}

// Example usage and print inversion count
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    divide(arr, 0, arr.size() - 1);
    cout << "Sorted array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;
    cout << "Inversion count: " << inversionCount << endl;
    return 0;
}

