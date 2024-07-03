import tkinter as tk
import math

class Gauge(tk.Canvas):
    def __init__(self, master=None, **kwargs):
        super().__init__(master, **kwargs)
        self.configure(width=200, height=200, bg='white')

        # Define gauge parameters
        self.min_value = 0
        self.max_value = 100
        self.value = 0

        # Center coordinates and radius of the gauge
        self.cx = self.winfo_width() // 2
        self.cy = self.winfo_height() // 2
        self.radius = min(self.cx, self.cy) - 10

        # Create elements of the gauge
        self.create_arc_gauge()

    def create_arc_gauge(self):
        start_angle = 135  # Start angle of the gauge arc (in degrees)
        end_angle = 45     # End angle of the gauge arc (in degrees)
        angle_range = end_angle - start_angle

        # Calculate the current angle based on the current value
        if self.max_value > self.min_value:
            angle = start_angle + (self.value - self.min_value) / (self.max_value - self.min_value) * angle_range
        else:
            angle = start_angle

        # Convert angle from degrees to radians
        start_angle_rad = math.radians(start_angle)
        angle_rad = math.radians(angle)

        # Calculate the coordinates of the arc
        x1 = self.cx + self.radius * math.cos(start_angle_rad)
        y1 = self.cy - self.radius * math.sin(start_angle_rad)
        x2 = self.cx + self.radius * math.cos(angle_rad)
        y2 = self.cy - self.radius * math.sin(angle_rad)

        # Draw the gauge arc
        self.create_arc(self.cx - self.radius, self.cy - self.radius,
                        self.cx + self.radius, self.cy + self.radius,
                        start=start_angle, extent=-angle_range,
                        style=tk.ARC, width=10, outline='blue')

        # Draw a line indicating the current value
        self.create_line(self.cx, self.cy, x2, y2, width=5, fill='red')

    def set_value(self, value):
        self.value = value
        self.delete("all")  # Clear the canvas
        self.create_arc_gauge()  # Redraw the gauge with the updated value

# Create a Tkinter application
root = tk.Tk()
root.title("Gauge")

# Create a Gauge widget
gauge = Gauge(root)
gauge.pack(padx=20, pady=20)

# Example of updating the gauge value (replace with your own logic)
def update_gauge_value():
    new_value = int(scale.get())  # Get value from a scale widget or another source
    gauge.set_value(new_value)

# Create a scale widget to simulate changing values
scale = tk.Scale(root, from_=0, to=100, orient=tk.HORIZONTAL, command=update_gauge_value)
scale.pack(pady=10)

# Set an initial value for the gauge
gauge.set_value(50)

# Run the Tkinter event loop
root.mainloop()
