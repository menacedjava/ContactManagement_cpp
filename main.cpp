#include <iostream>
#include <vector>

using namespace std;

// Kontaktlar uchun struct
struct Contact {
    string name;
    string phone;
};

// Kontaktlar ro‘yxati
vector<Contact> contacts;

// Yangi kontakt qo‘shish funksiyasi
void addContact() {
    Contact newContact;
    cout << "Ism kiriting: ";
    cin >> newContact.name;
    cout << "Telefon raqam kiriting: ";
    cin >> newContact.phone;

    contacts.push_back(newContact);
    cout << "Kontakt muvaffaqiyatli qo‘shildi!\n";
}

// Kontaktlarni chiqarish funksiyasi
void showContacts() {
    if (contacts.empty()) {
        cout << "Kontaktlar ro‘yxati bo‘sh!\n";
        return;
    }
    cout << "\n--- Kontaktlar ro‘yxati ---\n";
    for (const auto &c : contacts) {
        cout << "Ism: " << c.name << ", Telefon: " << c.phone << endl;
    }
}

// Kontakt qidirish funksiyasi
void searchContact() {
    string searchName;
    cout << "Qidirilayotgan ismni kiriting: ";
    cin >> searchName;

    for (const auto &c : contacts) {
        if (c.name == searchName) {
            cout << "Topildi! Ism: " << c.name << ", Telefon: " << c.phone << endl;
            return;
        }
    }
    cout << "Bunday ismli kontakt topilmadi!\n";
}


int main() {
    int choice;
    do {
        cout << "\n1. Kontakt qo‘shish\n2. Kontaktlarni ko‘rish\n3. Kontakt qidirish\n0. Chiqish\nTanlang: ";
        cin >> choice;

        switch (choice) {
            case 1: addContact(); break;
            case 2: showContacts(); break;
            case 3: searchContact(); break;
            case 0: cout << "Dasturdan chiqilmoqda...\n"; break;
            default: cout << "Noto‘g‘ri tanlov!\n";
        }
    } while (choice != 0);

    return 0;
}
