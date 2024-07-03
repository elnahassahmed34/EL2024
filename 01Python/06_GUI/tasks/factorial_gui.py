import tkinter as tk
from tkinter import messagebox

# Function to calculate factorial
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

# Function to handle button click event
def calculate_factorial():
    try:
        # Get the input from the Entry widget
        num = int(entry.get())

        # Calculate factorial
        result = factorial(num)

        # Display the result using a message box
        messagebox.showinfo("Factorial Result", f"The factorial of {num} is {result}")

    except ValueError:
        messagebox.showerror("Error", "Please enter a valid integer.")

# Create the main application window
root = tk.Tk()
root.title("Factorial Calculator")

# Create and place widgets
label = tk.Label(root, text="Enter an integer N:")
label.pack()

entry = tk.Entry(root)
entry.pack()

calculate_button = tk.Button(root, text="Calculate Factorial", command=calculate_factorial)
calculate_button.pack()

# Run the application
root.mainloop()
