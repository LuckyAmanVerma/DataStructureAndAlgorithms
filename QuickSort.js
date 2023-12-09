/*
Using Quick Sort , Worst Case n*n , Average and Best nlogn
*/
function partition(arr = [], low, high) {
    let pivot = arr[high];
    let i = low - 1;
    for (let j = low; j < arr.length; j++) {
      if (arr[j] < pivot) {
        i++;
        let temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    i++;
    let temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
  }
  function quickSort(arr = [], low, high) {
    if (low < high) {
      let pivot = partition(arr, low, high);
      quickSort(arr, low, pivot - 1);
      quickSort(arr, pivot + 1, high);
    }
  }
  
  let array = [5, 7, 2, 4, 1];
  let n = array.length;
  quickSort(array, 0, n - 1);
  console.log(array);
  