def selectionSort(arr):
    for i in range(0, len(arr)):
        min_element_id = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_element_id]:
                min_element_id = j 
        curr_smallest = arr[min_element_id]
        arr[min_element_id] = arr[i]
        arr[i] = curr_smallest
        
arr = [9,2,5,-3,0,-85,1]
selectionSort(arr)
print(arr)