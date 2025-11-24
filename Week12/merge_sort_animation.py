import matplotlib.pyplot as plt
import matplotlib.animation as animation
import random

def merge_sort_animation(n=30):
    # Generate random data
    arr = [random.randint(1, 100) for _ in range(n)]
    
    # Create figure and axis
    fig, ax = plt.subplots()
    ax.set_title("Merge Sort Animation")
    
    # Create bar chart
    bar_rects = ax.bar(range(len(arr)), arr, align="edge")
    
    # Set axis limits
    ax.set_xlim(0, n)
    ax.set_ylim(0, int(1.1 * max(arr)))
    
    # Text for operations
    text = ax.text(0.02, 0.95, "", transform=ax.transAxes)
    
    # Generator for merge sort steps
    def merge_sort_steps(arr, start, end):
        if end - start > 1:
            mid = (start + end) // 2
            yield from merge_sort_steps(arr, start, mid)
            yield from merge_sort_steps(arr, mid, end)
            yield from merge_steps(arr, start, mid, end)
            
    def merge_steps(arr, start, mid, end):
        left = arr[start:mid]
        right = arr[mid:end]
        
        i = j = 0
        k = start
        
        while i < len(left) and j < len(right):
            # Yield current state: range being merged (yellow), current comparison (red)
            yield arr, range(start, end), k
            
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1
            
        while i < len(left):
            yield arr, range(start, end), k
            arr[k] = left[i]
            i += 1
            k += 1
            
        while j < len(right):
            yield arr, range(start, end), k
            arr[k] = right[j]
            j += 1
            k += 1
            
        yield arr, range(start, end), -1 # End of merge for this range

    # Animation update function
    def update(data):
        arr, active_range, active_idx = data
        
        for i, rect in enumerate(bar_rects):
            rect.set_height(arr[i])
            
            if i in active_range:
                if i == active_idx:
                    rect.set_color('red') # Currently placing
                else:
                    rect.set_color('yellow') # In active merge range
            else:
                rect.set_color('skyblue') # Inactive
                
        text.set_text(f"Merging range {active_range.start}-{active_range.stop}")

    # Create animation
    generator = merge_sort_steps(arr, 0, len(arr))
    
    anim = animation.FuncAnimation(
        fig, 
        update, 
        frames=generator, 
        repeat=False,
        interval=50, # Speed of animation in ms
        save_count=1000
    )
    
    plt.show()

if __name__ == "__main__":
    print("Starting Merge Sort Animation...")
    print("A window should open showing the animation.")
    merge_sort_animation()
