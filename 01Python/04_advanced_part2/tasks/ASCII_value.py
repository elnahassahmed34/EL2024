def get_ascii_value(character):
    return ord(character)

def main():
    # Prompt the user to enter a character
    char = input("Enter a character: ")

    # Ensure that only one character is entered
    if len(char) != 1:
        print("Please enter a single character.")
    else:
        ascii_value = get_ascii_value(char)
        print(f"The ASCII value of '{char}' is {ascii_value}.")

if __name__ == "__main__":
    main()
