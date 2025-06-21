/*
heap =[1,2,3,4];
delete root element , 
 move last element to root,
 heap =[4,2,3];
 Now move 4 to its correct position
*/

heap.delete();
class MinHeap {
public:
    int size;
    vector<int> heap; // Use std::vector for dynamic array  [1,2,3,4]

    MinHeap() : size(0) {}
	void delete(){
        if(size==0){
            cout << "Heap is empty, nothing to delete." << endl;
            return;
        }
        heap[0]=heap[size-1]; // Move last element to root [4,1,2]
        size--; // Decrease size
        heap.pop_back(); // Remove last element from vector  Remove 1 from vector
        // now heapify the heap
        if(size == 0) {
            cout << "Heap is now empty." << endl;
            return;
        }
        heapify(0); // Start heapifying from root
        cout << "Deleted root element, new heap: ";
    }

    void heapify(int idx) {   //[4,1,2]
        int leftChild = 2 * idx + 1;  //1
        int rightChild = 2 * idx + 2;//2
        int smallest = idx;//0
        if(leftChild<size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if(rightChild<size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }
        if(smallest != idx) {
            swap(heap[idx], heap[smallest]);
            heapify(smallest); // Recursively heapify the affected subtree
        }
    }
}