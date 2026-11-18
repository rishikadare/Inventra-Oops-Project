# INVENTRA – Inventory Management System

A mini-project for the OOPS practical, built around an inventory management theme.

## Project contents
- `web/index.html` – dark-themed interactive dashboard (runs in a browser; uses localStorage for demo data).
- `cpp/main.cpp` – C++ console application demonstrating object-oriented programming.
- `cpp/inventory.txt` – generated when the C++ program saves inventory data.

## Run the dark dashboard
1. Open `web/index.html` in Chrome, Edge, Firefox, or Safari.
2. Add, edit, search, and delete products. Demo changes are saved in browser localStorage.

## Run the C++ OOPS application
Requires a C++11-or-newer compiler.

### macOS / Linux
```bash
cd cpp
g++ -std=c++11 -Wall -Wextra main.cpp -o inventra
./inventra
```

### Windows (MinGW)
```bash
cd cpp
g++ -std=c++11 -Wall -Wextra main.cpp -o inventra.exe
inventra.exe
```

## OOPS concepts demonstrated
- **Class and Object:** `Product` and `Inventory`.
- **Encapsulation:** Product data members are private and accessed through public methods.
- **Inheritance:** `Product` inherits from abstract base class `Record`.
- **Abstraction:** `Record` defines the common `display()` interface.
- **Polymorphism:** `display()` is virtual and overridden by `Product`.
- **File handling:** Inventory records can be saved to `inventory.txt`.

## Features
- Add, view, search, update and delete products.
- Check total inventory value.
- Save C++ inventory records to a text file.
- Dark dashboard with product search, stock status, low-stock alerts and category distribution.

## Note
The browser dashboard and C++ console program are two demonstrations of the same project theme. The HTML dashboard is a front-end demo and does not call the C++ executable as a web server.
Your site is live at https://rishikadare.github.io/Inventra-Oops-Project/
