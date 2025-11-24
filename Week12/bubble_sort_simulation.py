import time

def bubble_sort_simulation(arr):
    n = len(arr)
    print(f"Initial list: {arr}")
    print("-" * 30)
    
    for i in range(n):
        swapped = False
        print(f"Pass {i + 1}:")
        
        for j in range(0, n - i - 1):
            print(f"  Comparing index {j} ({arr[j]}) and {j+1} ({arr[j+1]})", end="")
            
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
                print(f" -> SWAP -> {arr}")
            else:
                print(f" -> NO SWAP")
            
            # Optional: Add a small delay for better visualization if running in a terminal
            # time.sleep(0.5) 
            
        print(f"End of Pass {i + 1}. Current list: {arr}")
        print("-" * 30)
        
        if not swapped:
            print("No swaps needed in this pass. List is sorted!")
            break
            
    return arr

if __name__ == "__main__":
    # Example list
    sample_list = [64, 34, 25, 12, 22, 11, 90]
    
    print("Starting Bubble Sort Simulation...")
    sorted_list = bubble_sort_simulation(sample_list)
    print(f"Sorted list: {sorted_list}")
