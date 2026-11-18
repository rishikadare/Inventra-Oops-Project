#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

// Base class demonstrates inheritance and runtime polymorphism.
class Record {
public:
    virtual void display() const = 0;
    virtual ~Record() {}
};

// Product encapsulates its data using private members.
class Product : public Record {
private:
    int id, quantity;
    string name, category;
    double price;

public:
    Product() : id(0), quantity(0), price(0) {}
    Product(int i, string n, string c, int q, double p)
        : id(i), quantity(q), name(n), category(c), price(p) {}

    int getId() const { return id; }
    int getQuantity() const { return quantity; }
    double getValue() const { return quantity * price; }

    void setQuantity(int q) { if (q >= 0) quantity = q; }

    void display() const override {
        cout << left << setw(6) << id << setw(22) << name
             << setw(16) << category << setw(10) << quantity
             << fixed << setprecision(2) << price << '\n';
    }

    void save(ofstream &out) const {
        out << id << '|' << name << '|' << category << '|'
            << quantity << '|' << price << '\n';
    }

    friend istream& operator>>(istream &in, Product &p) {
        in >> p.id;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(in, p.name);
        getline(in, p.category);
        in >> p.quantity >> p.price;
        return in;
    }
};

class Inventory {
private:
    vector<Product> products;
    int nextId = 1;

    int findIndex(int id) const {
        for (int i = 0; i < (int)products.size(); i++)
            if (products[i].getId() == id) return i;
        return -1;
    }

public:
    void addProduct() {
        string name, category;
        int quantity;
        double price;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Product name: "; getline(cin, name);
        cout << "Category: "; getline(cin, category);
        cout << "Quantity: "; cin >> quantity;
        cout << "Unit price: "; cin >> price;
        if (quantity < 0 || price < 0) {
            cout << "Quantity and price cannot be negative.\n";
            return;
        }
        products.emplace_back(nextId++, name, category, quantity, price);
        cout << "Product added successfully.\n";
    }

    void viewProducts() const {
        if (products.empty()) { cout << "Inventory is empty.\n"; return; }
        cout << left << setw(6) << "ID" << setw(22) << "NAME"
             << setw(16) << "CATEGORY" << setw(10) << "QTY" << "PRICE\n";
        cout << string(65, '-') << '\n';
        for (const Product &p : products) p.display();
    }

    void updateStock() {
        int id, quantity;
        cout << "Enter product ID: "; cin >> id;
        int index = findIndex(id);
        if (index == -1) { cout << "Product not found.\n"; return; }
        cout << "Enter new quantity: "; cin >> quantity;
        if (quantity < 0) { cout << "Invalid quantity.\n"; return; }
        products[index].setQuantity(quantity);
        cout << "Stock updated.\n";
    }

    void deleteProduct() {
        int id;
        cout << "Enter product ID: "; cin >> id;
        int index = findIndex(id);
        if (index == -1) { cout << "Product not found.\n"; return; }
        products.erase(products.begin() + index);
        cout << "Product deleted.\n";
    }

    void searchProduct() const {
        int id;
        cout << "Enter product ID: "; cin >> id;
        int index = findIndex(id);
        if (index == -1) cout << "Product not found.\n";
        else products[index].display();
    }

    void showValue() const {
        double total = 0;
        for (const Product &p : products) total += p.getValue();
        cout << fixed << setprecision(2)
             << "Total inventory value: Rs. " << total << '\n';
    }

    void saveToFile() const {
        ofstream out("inventory.txt");
        for (const Product &p : products) p.save(out);
        cout << "Inventory saved to inventory.txt\n";
    }
};

int main() {
    Inventory inventory;
    int choice;
    do {
        cout << "\n========== INVENTRA ==========\n"
             << "1. Add Product\n2. View Products\n3. Update Stock\n"
             << "4. Delete Product\n5. Search Product\n"
             << "6. Total Inventory Value\n7. Save to File\n0. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: inventory.addProduct(); break;
            case 2: inventory.viewProducts(); break;
            case 3: inventory.updateStock(); break;
            case 4: inventory.deleteProduct(); break;
            case 5: inventory.searchProduct(); break;
            case 6: inventory.showValue(); break;
            case 7: inventory.saveToFile(); break;
            case 0: inventory.saveToFile(); cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    return 0;
}
