/*
Bucket Sort Algorithm
1. Create an array of empty "buckets".
2. Distribute the input array elements into the buckets.
3. Sort each bucket (using another sorting algorithm or recursively).
4. Concatenate the sorted buckets into a single output array.
Time Complexity: Best and Average O(n + k), Worst O(n^2) (if buckets are not sorted well).
Space Complexity: O(n + k) for the buckets.
Drawbacks:
- Not suitable for small datasets.
- Requires knowledge of the range of input values. - if the range of elements is known or small.
- Performance depends on the distribution of input values.
Rule of thumb:
counts.length = max(arr) – min(arr) + 1
input=[2,1,2,2,0,0,2]

After Bucket - [2,1,4]
Not Stable
Specified Range -- Specified Range -- Specified Range-- Specified Range -- Specified Range -- Specified Range
*/

vector<int> bucketSort(vector<int> array) {
    int countLength = (*max_element(array.begin(), array.end()) -
                       *min_element(array.begin(), array.end())) + 1;

    vector<int> counts(countLength, 0);

    for (int i = 0; i < array.size(); i++) {
        counts[array[i]] += 1;
    }

    int i = 0;
    for (int j = 0; j < counts.size(); j++) {
        for (int k = 0; k < counts[j]; k++) {
            array[i++] = j;
        }
    }

    return array;
}

/*
For Decimal Values: Time Complexity: O(n + k), Space Complexity: O(n + k)
*/

vector<float> bucketSort(vector<float> array) {
    int scale = 100; // for 2 decimal places

    // Step 1: Scale all values to integers
    vector<int> scaled(array.size());
    for (int i = 0; i < array.size(); i++) {
        scaled[i] = array[i] * scale;
    }

    // Step 2: Apply original counting logic
    int countLength = (*max_element(scaled.begin(), scaled.end()) -
                       *min_element(scaled.begin(), scaled.end())) + 1;

    vector<int> counts(countLength, 0);

    for (int i = 0; i < scaled.size(); i++) {
        counts[scaled[i] - *min_element(scaled.begin(), scaled.end())] += 1;
    }

    // Step 3: Reconstruct sorted scaled array
    int idx = 0;
    for (int j = 0; j < counts.size(); j++) {
        for (int k = 0; k < counts[j]; k++) {
            scaled[idx++] = j + *min_element(scaled.begin(), scaled.end());
        }
    }

    // Step 4: Scale back to float
    for (int i = 0; i < array.size(); i++) {
        array[i] = scaled[i] / (float)scale;
    }

    return array;
}

