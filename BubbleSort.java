// Online Java Compiler
// Use this editor to write, compile and run your Java code online
//O(n*n)

class BubbleSort{
    public static void printList(int arr[]){
        for(int i=0;i<arr.length;i++){
            System.out.println(arr[i]+" ");
        }
    }
    public static void main(String[] args) {
        int arr[]={64, 34, 25, 12, 22, 11, 90};
        for(int i=0;i<arr.length-1;i++){
            for(int j=0;j<arr.length-i-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp= arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        printList(arr);
    }
}