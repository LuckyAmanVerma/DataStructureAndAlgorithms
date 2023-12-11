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