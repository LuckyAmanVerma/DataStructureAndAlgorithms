/*
O(logn)
Searching an sorted array
[1,3,5,22,24,27,30]
*/
class BinarySearch{
    public static int search(int arr[],int low,int high,int num){
        int mid = Math.round(low+(high-low)/2);
        if(low<=high){
             if(arr[mid]==num){
            return mid;
        }
       if(arr[mid]<num){
        return search(arr,mid+1,high,num);
       }
       else{
         return search(arr,low,mid,num);
       }
        }
        return -1;
    }
    public static void main(String args[]){
        int arr[]={1,3,4,5,6,8,9,11,32,44};
        int num=32;
        System.out.println(search(arr,0,arr.length-1,num));
    }
}