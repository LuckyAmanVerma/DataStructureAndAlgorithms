/*
Divide and conquer appraoch
Take more memory compare to quick sort , as new array is created , 
nLogn Average and best case scenario,
Take extra space for merging
*/

 public class MergeSort{
    public static void mergeSort(int arr[],int start,int mid,int end){
        int merged[]= new int[end-start+1];
        int idx1=start;
        int idx2=mid+1;
        int i=0;
        while(idx1<=mid && idx2<=end){
            if(arr[idx1]<=arr[idx2]){
                merged[i++]=arr[idx1++];
            }
            else{
                merged[i++]=arr[idx2++];
            }   
        }
    
        while(idx1<=mid){
                merged[i++]=arr[idx1++];
        }

        while(idx2<=end){
                merged[i++]=arr[idx2++];
        }
         // Copy sorted values back to the original array
        for(int x=0,j=start;x<merged.length;x++,j++ ){
            arr[j]=merged[x];
        }

    }
    public static void merge(int arr[],int start,int end){
        if(start<end){
        int mid = start +(end-start)/2;
        merge(arr,start,mid);
        merge(arr,mid+1,end);
        mergeSort(arr,start,mid,end);
        }
    }
    public static void main(String args[])
    {
        int arr[] = { 12, 11, 13, 5, 6, 7 };
        int n=arr.length;
        merge(arr,0,n-1);
       for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}