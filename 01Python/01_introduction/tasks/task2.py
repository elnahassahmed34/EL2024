# Function to compute the area of a circle
def compute_area(radius):
    pi = 3.141592653589793
    return pi * (radius ** 2)

# Get user input
radius = float(input("Enter the radius of the circle: "))

# Compute the area
area = compute_area(radius)

# Print the result
print(f"The area of the circle with radius {radius} is: {area}")
