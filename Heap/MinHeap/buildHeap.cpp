/*
convert an array in heap
heap = [7, 10, 4, 3, 20, 15]   
        7
      /   \
    10     4
   /  \   /
  3   20 15

*/

class MinHeap {
public:
    int size;
    vector<int> heap; 

    MinHeap() : size(0) {}

  void buildHeap(){
        if(size == 0) {
            cout << "Heap is empty, nothing to bubble up." << endl;
            return;
        }
       for(int i = (size / 2) - 1; i >= 0; i--){
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        if(leftChild < size && heap[leftChild] < heap[i]) {
            swap(heap[i], heap[leftChild]);
        }
        if(rightChild < size && heap[rightChild] < heap[i]) {
            swap(heap[i], heap[rightChild]);
        }
       }
        cout << "Heap after bubbling up: " <<endl;
        for(int i=0;i<size;i++){
            cout << heap[i] << " ";
        }     
        
    }
  

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
