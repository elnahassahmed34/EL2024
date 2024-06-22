import fave_sites

def print_menu():
    """
    Prints a menu of favorite websites for the user to choose from.
    """
    print("Favorite Websites:")
    for index, site in enumerate(fave_sites.favorite_websites.keys(), start=1):
        print(f"{index}. {site}")

def main():
    print_menu()
    
    try:
        choice = int(input("Enter the number of the website you want to open: "))
        if 1 <= choice <= len(fave_sites.favorite_websites):
            site_name = list(fave_sites.favorite_websites.keys())[choice - 1]
            fave_sites.firefox(fave_sites.favorite_websites[site_name])
        else:
            print("Invalid choice. Please choose a valid number.")
    except ValueError:
        print("Invalid input. Please enter a number.")

if __name__ == "__main__":
    main()
