import tkinter as tk

# Function to change the LED state and update the circle color
def toggle_led(state):
    if state == "on":
        led_state.set("ON")
        canvas.itemconfig(circle, fill="red")
    elif state == "off":
        led_state.set("OFF")
        canvas.itemconfig(circle, fill="white")

# Create the main application window
root = tk.Tk()
root.title("LED Control")

# Variables to track LED state
led_state = tk.StringVar()
led_state.set("OFF")  # Initial state

# Canvas for drawing
canvas = tk.Canvas(root, width=200, height=200)
canvas.pack()

# Draw the circle
circle = canvas.create_oval(50, 50, 150, 150, fill="white")

# Buttons to control the LED
on_button = tk.Button(root, text="ON", command=lambda: toggle_led("on"))
on_button.pack(side=tk.LEFT, padx=10)

off_button = tk.Button(root, text="OFF", command=lambda: toggle_led("off"))
off_button.pack(side=tk.RIGHT, padx=10)

# Label to display LED state
state_label = tk.Label(root, textvariable=led_state, font=("Arial", 18))
state_label.pack(pady=20)

# Run the application
root.mainloop()
