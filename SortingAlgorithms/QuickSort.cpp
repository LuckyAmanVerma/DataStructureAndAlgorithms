/*
Quick Sort
Time Complexity: O(n log n) on average, O(n^2) in the worst case (when the pivot is the smallest or largest element).
Space Complexity: O(log n) due to recursive stack space.

Best for large datasets and when average-case performance is more important than worst-case performance.

कब Quick Sort का इस्तेमाल करें (When to use Quick Sort):
- जब आपको fast sorting चाहिए (average case O(n log n))
- जब array बहुत बड़ा हो (in-place sorting और O(log n) space)
- जब random data हो (average case में अच्छा प्रदर्शन)

कब Quick Sort worst choice है:
- जब array पहले से sorted हो (worst case O(n^2))
- जब memory constraint हो (क्योंकि recursive stack space O(log n) चाहिए)
- जब stable sort चाहिए (quick sort stable नहीं है)
example:
[5,2,6,4,1,3] 
https://www.youtube.com/watch?v=8MNB0Mba_Dc
index=0,[2,5,6,4,1,3]
index=0 j =4 
    index+=1 , index=1 ,j=4 swap [2,1,5,6,4,3]  
    swap pivot   , index+1 , return index+1

    Partition Logic: initialise index to -1 , and run j for start to end-1 , as last element is pivot
    when find value less than pivot , increment index by 1 , then swap index with ar jth elements , 

*/

void quickSort(vector<int> &nums,int start,int end){
    if(start<end){
        int pivotIndex = partition(nums,start,end);
        quickSort(nums,start,pivotIndex-1);
        quickSort(nums,pivotIndex+1,end);
    }

}

int partition(vector<int> &nums,int start,int end) {
    int pivot = end; // fix: add missing semicolon
    int index = start - 1; // fix: index should start from start-1
    for(int i = start; i < end; i++){
        if(nums[i] < nums[pivot]){
            index += 1;
            swap(nums[i], nums[index]);
        }
    }
    swap(nums[index + 1], nums[pivot]); // fix: place pivot in correct position
    return index + 1;
}
