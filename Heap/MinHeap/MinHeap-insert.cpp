
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
		heap[size-1]=val;    // 
		size++;
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
		heap[size]=val;    //  heap=[2,1]
		size++;           //size=2
		......
		// Now we have to check , If new value is in its correct position
		while (size>1){
			int parent = (size-1)/2;   // 1
			if(heap[parent]>heap[size-1]){   // 2 is greater than 1 
				swap(heap[parent],heap[size-1]);   //after swap [1,2]
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