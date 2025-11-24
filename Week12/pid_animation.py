import matplotlib.pyplot as plt
import matplotlib.animation as animation
import time

class PIDController:
    def __init__(self, Kp, Ki, Kd, setpoint=0):
        self.Kp = Kp
        self.Ki = Ki
        self.Kd = Kd
        self.setpoint = setpoint
        
        self.prev_error = 0
        self.integral = 0
        self.last_time = None
        
    def update(self, current_value, dt):
        error = self.setpoint - current_value
        
        # Proportional term
        P = self.Kp * error
        
        # Integral term
        self.integral += error * dt
        I = self.Ki * self.integral
        
        # Derivative term
        derivative = (error - self.prev_error) / dt
        D = self.Kd * derivative
        
        # Calculate output
        output = P + I + D
        
        # Save state for next update
        self.prev_error = error
        
        return output

def pid_animation():
    # PID Parameters
    Kp = 0.5
    Ki = 0.05
    Kd = 0.1
    setpoint = 10
    
    pid = PIDController(Kp, Ki, Kd, setpoint=setpoint)
    
    # System state
    current_value = 0
    velocity = 0
    dt = 0.1
    
    # Data for plotting
    times = [0]
    values = [0]
    setpoints = [setpoint]
    
    # Create figure
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(8, 8))
    fig.suptitle(f"PID Control Animation (Kp={Kp}, Ki={Ki}, Kd={Kd})")
    
    # Plot 1: Time Series
    line_pv, = ax1.plot([], [], label='Process Variable', color='blue')
    line_sp, = ax1.plot([], [], label='Setpoint', color='red', linestyle='--')
    ax1.set_xlim(0, 20)
    ax1.set_ylim(0, 15)
    ax1.set_xlabel('Time')
    ax1.set_ylabel('Value')
    ax1.legend()
    ax1.grid(True)
    
    # Plot 2: Visual Representation (e.g., a car moving to a line)
    ax2.set_xlim(0, 15)
    ax2.set_ylim(-1, 1)
    ax2.set_yticks([])
    ax2.set_xlabel('Position')
    
    target_line = ax2.axvline(x=setpoint, color='red', linestyle='--', label='Target')
    object_marker, = ax2.plot([], [], 'bo', markersize=15, label='Object')
    ax2.legend()
    ax2.grid(True)
    
    def init():
        line_pv.set_data([], [])
        line_sp.set_data([], [])
        object_marker.set_data([], [])
        return line_pv, line_sp, object_marker
    
    def update(frame):
        nonlocal current_value, velocity
        
        # PID Control
        control = pid.update(current_value, dt)
        
        # Physics Simulation
        velocity += control * dt
        velocity *= 0.95 # Friction
        current_value += velocity * dt
        
        # Store data
        current_time = frame * dt
        times.append(current_time)
        values.append(current_value)
        setpoints.append(setpoint)
        
        # Update Plot 1
        line_pv.set_data(times, values)
        line_sp.set_data(times, setpoints)
        
        # Adjust x-axis if needed
        if current_time > ax1.get_xlim()[1]:
            ax1.set_xlim(0, current_time + 10)
            
        # Update Plot 2
        object_marker.set_data([current_value], [0])
        
        return line_pv, line_sp, object_marker
    
    anim = animation.FuncAnimation(
        fig, 
        update, 
        init_func=init,
        frames=200, 
        interval=50, 
        blit=True
    )
    
    plt.show()

if __name__ == "__main__":
    print("Starting PID Animation...")
    print("A window should open showing the animation.")
    pid_animation()
