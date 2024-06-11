import calendar

# Get user input for year and month
year = int(input("Enter the year: "))
month = int(input("Enter the month (1-12): "))

# Print the calendar for the specified month and year
print(calendar.month(year, month))
