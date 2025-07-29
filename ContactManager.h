#ifndef CONTACTMANGER_H 
#define CONTACTMANGER_H
#include<iostream>
#include<string>
#include "Trie.h"

using namespace std;


TrieNodes ContactManager;

void mainCode(){
     for(int i=0;i<500;i++) {
        cout << "\n--- Contact Management Menu ---\n";
        cout << "1. Insert Contact\n";
        cout << "2. Search Full Name\n";
        cout << "3. Search by Prefix\n";
        cout << "4. Delete Contact\n";
        cout << "5. Display All Contacts\n";
        cout << "6. Exit\n";
        cout << "Enter number: ";
        int number;
        cin >> number;
        cin.ignore(); // flush newline from input buffer
        if (number == 1) {
            string name, email, address, phone;
            cout << "Enter full name: ";
            getline(cin, name);
            cout << "Enter email: ";
            getline(cin, email);
            cout << "Enter phone number: ";
            getline(cin, phone);
            cout << "Enter address: ";
            getline(cin, address);
            ContactManager.Insert(name, email, phone, address);
            cout << "Contact inserted successfully.\n";
        }
        else if (number == 2) {
            string name;
            cout << "Enter full name to search: ";
            getline(cin, name);
            if (ContactManager.search(name)) {
                cout << "Contact found:\n";
                ContactManager.prefixSearch(name); // since collectSuggestions prints details
            } else {
                cout << "No contact with that name.\n";
            }
        }
        else if (number == 3) {
            string prefix;
            cout << "Enter prefix: ";
            getline(cin, prefix);
            cout << "Contacts starting with '" << prefix << "':\n";
            ContactManager.prefixSearch(prefix);
        }
        else if (number == 4) {
            string name;
            cout << "Enter full name to delete: ";
            getline(cin, name);
            if (ContactManager.deleteIt(name)) {
                cout << "Contact deleted.\n";
            } else {
                cout << "Contact not found.\n";
            }
        }
        else if (number == 5) {
            cout << "\nAll contacts:\n";
            ContactManager.displayall();
        }
        else if (number == 6) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid option. Try again.\n";
        }
    }
}

#endif