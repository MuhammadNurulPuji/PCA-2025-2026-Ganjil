import matplotlib.pyplot as plt
import matplotlib.animation as animation
import random

def bubble_sort_animation(n=20):
    # Generate random data
    arr = [random.randint(1, 100) for _ in range(n)]
    
    # Create figure and axis
    fig, ax = plt.subplots()
    ax.set_title("Bubble Sort Animation")
    
    # Create bar chart
    bar_rects = ax.bar(range(len(arr)), arr, align="edge")
    
    # Set axis limits
    ax.set_xlim(0, n)
    ax.set_ylim(0, int(1.1 * max(arr)))
    
    # Text for operations
    text = ax.text(0.02, 0.95, "", transform=ax.transAxes)
    
    # Generator for bubble sort steps
    def bubble_sort_steps(arr):
        n = len(arr)
        for i in range(n):
            for j in range(0, n - i - 1):
                yield arr, j, j + 1, -1, -1 # Yield current state and indices being compared
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
                    yield arr, j, j + 1, j, j + 1 # Yield state after swap
            yield arr, -1, -1, -1, -1 # End of pass
            
    # Animation update function
    def update(data):
        arr, compare_idx1, compare_idx2, swap_idx1, swap_idx2 = data
        
        for rect, val in zip(bar_rects, arr):
            rect.set_height(val)
            rect.set_color('skyblue') # Reset color
            
        if compare_idx1 != -1:
            bar_rects[compare_idx1].set_color('yellow')
            bar_rects[compare_idx2].set_color('yellow')
            text.set_text(f"Comparing indices {compare_idx1} and {compare_idx2}")
            
        if swap_idx1 != -1:
            bar_rects[swap_idx1].set_color('green')
            bar_rects[swap_idx2].set_color('green')
            text.set_text(f"Swapped indices {swap_idx1} and {swap_idx2}")

    # Create animation
    # Cache the generator to avoid restarting it
    generator = bubble_sort_steps(arr)
    
    anim = animation.FuncAnimation(
        fig, 
        update, 
        frames=generator, 
        repeat=False,
        interval=100, # Speed of animation in ms
        save_count=1000
    )
    
    plt.show()

if __name__ == "__main__":
    print("Starting Bubble Sort Animation...")
    print("A window should open showing the animation.")
    bubble_sort_animation()
