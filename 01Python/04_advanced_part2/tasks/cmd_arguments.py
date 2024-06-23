import sys

def main():
    # Check if there are any command-line arguments
    if len(sys.argv) < 2:
        print("No command-line arguments provided.")
    else:
        print("Command-line arguments:")
        for i, arg in enumerate(sys.argv):
            print(f"Argument {i}: {arg}")

if __name__ == "__main__":
    main()
