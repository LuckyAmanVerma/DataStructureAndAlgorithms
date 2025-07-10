/*
Input:[1,3,5,2,8,7,6] 

 How "Small" Is Small for Insertion Sort?
Insertion Sort tends to outperform more advanced algorithms when the input size is typically:
| Input Size | Insertion Sort Viability | 

| n ≤ 30 | Excellent — minimal overhead, fast comparisons | 
| n ≤ 50–100 | Competitive — depends on how sorted the input already is | 
| n > 100 | Merge/Quick Sort usually outperform due to reduced comparisons | 
 Time Complexity: O(n^2) in the worst case, O(n) in the best case (when the array is already sorted).
Space Complexity: O(1) — in-place sorting algorithm.

Best for small or nearly sorted arrays.

// कब Insertion Sort का इस्तेमाल करें (When to use Insertion Sort):
// - जब array छोटा हो (n <= 30 या n <= 50-100 और पहले से थोड़ा sorted हो)
// - जब array लगभग sorted हो (best case O(n))
// - जब stable sort चाहिए और memory constraint हो (O(1) space)
//
// कब Insertion Sort worst choice है:
// - जब array बहुत बड़ा हो (n > 100)
// - जब random/unordered data हो (worst case O(n^2))
// - जब high performance चाहिए large datasets पर (Merge/Quick Sort बेहतर हैं)

Yes, 900 > 147 if we look strictly at Big-O. But the constants in Merge/Quick Sort are much higher. 
Insertion Sort's tight loops, no recursion, and adaptive behavior make it faster for small arrays in real-world CPUs. 
That’s why it’s used in hybrid sort implementations for base cases under 32–64 elements.



*/

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && arr[j + 1] < arr[j]) {
            int tmp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = tmp;
            j -= 1;
        }
    }
}

