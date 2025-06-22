heap.insert(2);
class MinHeap { 
	{
		size:0,
		heap:[];    // []
	}
	void insert(int val){  val=2
		if(size===0){
			heap[size]=val; // heap=[2]
			size++;    // size=1
			return;
		}
		......
		// now i have to bubble up 
		
		
	}
}


heap.insert(1);

class MinHeap { 
	{
		size:0,
		heap:[];   
	}
	void insert(int val){  val=1    heap=[2]  size=1
		if(size===0){
			heap[size]=val; 
			size++;    
			return;
		}
		heap[size]=val;
		int current = size;    //  heap=[2,1]
		size++;           //size=2
		......
		// Now we have to check , If new value is in its correct position
		while (current>1){
			int parent = (current-1)/2;   // 1
			if(heap[parent]>heap[current-1]){   // 2 is greater than 1 
				swap(heap[parent],heap[current-1]);   //after swap [1,2]
			}  
			// heap =[1,2] size=2
			return;
		}
		
		
	}
}


heap.insert(4);

class MinHeap { 
	{
		int size=0,
		int heap=[];   
	}
	void insert(int val){  val=1    heap=[1,2]  size=2
		if(size===0){
			heap[size]=val; 
			size++;    
			return;
		}
		heap[size]=val;    //  heap=[1,2,4]
		size++;           //size=3
		......
		// Now we have to check , If new value is in its correct position
		while (size>0){
			int parent = (size/2)-1;   // 0
			if(heap[parent]>heap[size-1]){   // 1 is less than 4 , so it doesn't go inside if condition
				swap(heap[parent],heap[size-1]);   
			}  
			//heap=[1,2,4]  size =3
			return;
		}
		
		
	}
}

// Updated MinHeap class using dummy value at index 0 for easier indexing
class MinHeapDummy {
public:
    int size;
    vector<int> heap; // heap[0] is dummy, real heap starts from index 1

    MinHeapDummy() : size(0) {
        heap.push_back(-1); // dummy value at index 0
    }

    void insert(int val) {
        heap.push_back(val); // insert at the end
        size++;
        int current = size;
        // Bubble up
        while(current > 1 && heap[current/2] > heap[current]) {
            swap(heap[current/2], heap[current]);
            current = current/2;
        }
    }

    void printHeap() {
        for(int i = 1; i <= size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};