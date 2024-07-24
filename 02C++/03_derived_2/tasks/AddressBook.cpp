#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

class AddressBook {
private:
    std::vector<Contact> contacts;

    void displayContact(const Contact& contact) const {
        std::cout << "Name: " << contact.name << "\n"
                  << "Phone: " << contact.phone << "\n"
                  << "Email: " << contact.email << "\n"
                  << "---------------------------\n";
    }

public:
    void listAllContacts() const {
        if (contacts.empty()) {
            std::cout << "Address book is empty.\n";
            return;
        }
        for (const auto& contact : contacts) {
            displayContact(contact);
        }
    }

    void addContact(const std::string& name, const std::string& phone, const std::string& email) {
        contacts.push_back({name, phone, email});
        std::cout << "Contact added successfully.\n";
    }

    void removeContact(const std::string& name) {
        auto it = std::remove_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) {
            return contact.name == name;
        });
        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            std::cout << "Contact removed successfully.\n";
        } else {
            std::cout << "Contact not found.\n";
        }
    }

    void removeAllContacts() {
        contacts.clear();
        std::cout << "All contacts removed successfully.\n";
    }

    void searchContact(const std::string& name) const {
        auto it = std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) {
            return contact.name == name;
        });
        if (it != contacts.end()) {
            displayContact(*it);
        } else {
            std::cout << "Contact not found.\n";
        }
    }

    void updateContact(const std::string& name, const std::string& newPhone, const std::string& newEmail) {
        auto it = std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) {
            return contact.name == name;
        });
        if (it != contacts.end()) {
            it->phone = newPhone;
            it->email = newEmail;
            std::cout << "Contact updated successfully.\n";
        } else {
            std::cout << "Contact not found.\n";
        }
    }

    void closeBook() const {
        std::cout << "Address book closed.\n";
    }
};

int main() {
    AddressBook book;
    int choice;
    std::string name, phone, email;

    do {
        std::cout << "\nAddress Book Menu:\n"
                  << "1. List all contacts\n"
                  << "2. Add a contact\n"
                  << "3. Remove a contact\n"
                  << "4. Remove all contacts\n"
                  << "5. Search for a contact\n"
                  << "6. Update a contact\n"
                  << "7. Close the address book\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore('\n'); // Clear input buffer

        switch (choice) {
            case 1:
                book.listAllContacts();
                break;
            case 2:
                std::cout << "Enter name: ";
                std::getline(std::cin, name);
                std::cout << "Enter phone: ";
                std::getline(std::cin, phone);
                std::cout << "Enter email: ";
                std::getline(std::cin, email);
                book.addContact(name, phone, email);
                break;
            case 3:
                std::cout << "Enter name of the contact to remove: ";
                std::getline(std::cin, name);
                book.removeContact(name);
                break;
            case 4:
                book.removeAllContacts();
                break;
            case 5:
                std::cout << "Enter name of the contact to search: ";
                std::getline(std::cin, name);
                book.searchContact(name);
                break;
            case 6:
                std::cout << "Enter name of the contact to update: ";
                std::getline(std::cin, name);
                std::cout << "Enter new phone: ";
                std::getline(std::cin, phone);
                std::cout << "Enter new email: ";
                std::getline(std::cin, email);
                book.updateContact(name, phone, email);
                break;
            case 7:
                book.closeBook();
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}