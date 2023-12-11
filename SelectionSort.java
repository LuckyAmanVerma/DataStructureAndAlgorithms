class SelectionSort{
    public static int minimum(int arr[]){
        int first =arr[0];
        for(int i=0;i<arr.length;i++){
            if(arr[i]<first){
                first=arr[i];
            }
        }
        return first;
    }
    public static void sort(int arr[],int alreadySorted){
        
        int min =minimum(arr);
       let temp=arr[0];
       arr[0]=min;
       min=temp;
       return sort(arr,alreadySorted+1);
    }
    public static void main(String args[]){
        int arr[]={7,5,4,2,9,21,12,23};
        sort(arr,-1);
    }
}