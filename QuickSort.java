class QuickSort{
    public static int logic(int arr[],int low,int high){
        int pivot=arr[high];
        int x=low-1;
        for(int i=low;i<high;i++){
            if(arr[i]<pivot){
                x++;
                int temp=arr[x];
                arr[x]=arr[i];
                arr[i]=temp;
            }
        }
        x++;
        int temp= arr[x];
        arr[x]=arr[high];
        arr[high]=temp;

        return x;
    }
    public static void quickSort(int arr[],int low,int high){
        if(low>=high){
            return;
        }
        int pivot=logic(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
    public static void main(String args[]){
        int arr[]={5, 7, 2, 4, 1};
        int n=arr.length;
        quickSort(arr,0,n-1);
        for(int i=0;i<arr.length;i++){
            System.out.println(arr[i]+" ");
        }
    }
}

/**
 * 
 [5,7,2,4,1] Pivot 1 , 
 iteration i=0 , 5 <1 false , no swap , 
 iteration i=1 , 7 <1 false , no swap , 
 iteration i=2 , 2 <1 false , no swap , 
 iteration i=3 , 4 <1 false , no swap , 
 iteration i=4 , 1 <1 false , no swap ,

 So , for loop doesn't do anything , 

 now at last , we have to swap 
 increment pointer , x++;
 swap arr[x] with high; 
 */