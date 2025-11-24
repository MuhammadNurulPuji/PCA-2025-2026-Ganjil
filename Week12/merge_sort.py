def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    
    # Divide
    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]
    
    # Recursive calls
    left_sorted = merge_sort(left_half)
    right_sorted = merge_sort(right_half)
    
    # Merge
    return merge(left_sorted, right_sorted)

def merge(left, right):
    sorted_list = []
    i = j = 0
    
    # Compare and merge
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            sorted_list.append(left[i])
            i += 1
        else:
            sorted_list.append(right[j])
            j += 1
            
    # Append remaining elements
    sorted_list.extend(left[i:])
    sorted_list.extend(right[j:])
    
    return sorted_list

if __name__ == "__main__":
    # Example list
    data = [64, 34, 25, 12, 22, 11, 90]
    # data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    
    print("(Before) Unsorted array is:")
    print(data)
    print()
    
    sorted_data = merge_sort(data)
    
    print("(After) Sorted array is:")
    print(sorted_data)
