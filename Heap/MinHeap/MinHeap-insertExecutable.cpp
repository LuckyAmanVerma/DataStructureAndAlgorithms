#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;
    int size;
public:
    MinHeap() : size(0) {}

    void insert(int val) {
        heap.push_back(val);
        size++;
        int idx = size - 1;
        // Bubble up
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[parent] > heap[idx]) {
                swap(heap[parent], heap[idx]);
                idx = parent;
            } else {
                break;
            }
        }
    }

    void printHeap() {
        for (int i = 0; i < size; ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap;
    heap.insert(2);
    heap.insert(1);
    heap.insert(4);
    heap.printHeap(); // Should print the heap in array form
    return 0;
}
