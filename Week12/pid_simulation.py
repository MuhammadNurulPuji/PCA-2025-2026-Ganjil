import matplotlib.pyplot as plt
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
        
    def update(self, current_value, current_time=None):
        if current_time is None:
            current_time = time.time()
            
        if self.last_time is None:
            dt = 0.1 # Default small time step for first run
        else:
            dt = current_time - self.last_time
            if dt <= 0: dt = 0.001 # Prevent division by zero
            
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
        self.last_time = current_time
        
        return output

def simulate_system(steps=100):
    # PID Parameters
    Kp = 1.0
    Ki = 0.1
    Kd = 0.05
    
    pid = PIDController(Kp, Ki, Kd, setpoint=10)
    
    # System state
    current_value = 0
    velocity = 0
    
    # Data for plotting
    times = []
    values = []
    setpoints = []
    
    print(f"Starting PID Simulation (Kp={Kp}, Ki={Ki}, Kd={Kd})...")
    print("Target Setpoint: 10")
    
    for i in range(steps):
        t = i * 0.1 # Simulated time
        
        # Get control output from PID
        control = pid.update(current_value, current_time=t)
        
        # Simulate a simple physical system (e.g., mass-spring-damper or heating)
        # Here we use a simple inertia model: control affects velocity, velocity affects position
        velocity += control * 0.1 # F = ma -> a = F/m (assume m=1, dt=0.1)
        velocity *= 0.9 # Damping/Friction
        current_value += velocity * 0.1
        
        # Store data
        times.append(t)
        values.append(current_value)
        setpoints.append(pid.setpoint)
        
    # Plotting
    plt.figure(figsize=(10, 6))
    plt.plot(times, values, label='Process Variable (PV)')
    plt.plot(times, setpoints, 'r--', label='Setpoint (SP)')
    plt.title('PID Control Simulation')
    plt.xlabel('Time (s)')
    plt.ylabel('Value')
    plt.grid(True)
    plt.legend()
    plt.show()
    
    print("Simulation complete. Plot displayed.")

if __name__ == "__main__":
    simulate_system()
