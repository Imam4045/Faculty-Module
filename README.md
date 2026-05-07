# 🏫 Faculty Management System

This project is a console-based Faculty Management System built in C using a singly linked list. It lets you manage faculty records where you can add, remove, search, update, and display faculty profiles from a menu.

---

## 🚀 What This Program Can Do

- Add a new faculty member to the list
- Insert a faculty at any specific position
- Delete a faculty from any position
- Search for a faculty by their initials
- Modify an existing faculty's information
- Display all faculty records in a clean table
- Free all memory properly when you exit

---

## 👤 Faculty Information Stored

Each faculty record holds the following details:

| Field | Description |
|---|---|
| Name | Full name of the faculty |
| Initial | Short initials (e.g., `MRA`) |
| Address | Current address |
| Phone Number | Contact number |
| Designation | Academic rank (see below) |
| Department | Department they belong to (see below) |

### Designations
| Code | Title |
|---|---|
| 1 | Lecturer |
| 2 | Senior Lecturer |
| 3 | Associate Professor |
| 4 | Assistant Professor |
| 5 | Professor |

### Departments
| Code | Department |
|---|---|
| 10 | Computer Science and Engineering (CSE) |
| 11 | Electrical and Electronic Engineering (EEE) |
| 12 | Electronics and Communication Engineering (ECE) |
| 13 | Genetic Engineering and Biotechnology (GEB) |
| 14 | Pharmacy (PHARM) |
| 15 | Civil Engineering (CE) |
| 16 | Mathematics and Physical Sciences (MPS) |
| 20 | English |
| 21 | Law |
| 22 | Social Relations |
| 23 | Information Studies |
| 24 | Sociology |
| 30 | Business Administration (BA) |
| 31 | Economics |

---

## 📁 Project Files

```
Project/
│
├── Main.c              # Entry point — contains the menu and program flow
├── Faculty_Module.c    # All linked list functions and logic
└── Faculty_Module.h    # Header file — structs, enums, and function declarations
```

---

## ⚙️ How To Run The Project

This project needs **MSYS2's UCRT64 GCC compiler** to run. I recommend using the UCRT64 terminal instead of PowerShell or CMD as it works correctly with this compiler.

### Step 1: Open the UCRT64 Terminal

Go to this location on your computer and double-click `ucrt64.exe`:

```
C:\msys64\ucrt64.exe
```

A terminal window will open that looks like a bash shell.

### Step 2: Navigate To Your Project Folder

In the UCRT64 terminal, use the `cd` command to go to wherever you saved the project:

```bash
cd "............../Project"
```

Replace `..............` with your actual folder path. An easy way to find it is to **open your project folder in File Explorer**, click the address bar at the top, and copy the path from there.

### Step 3: Compile The Project

```bash
gcc Main.c Faculty_Module.c -o faculty_module.exe -Wall
```

This compiles both source files and creates `faculty_module.exe` in your project folder. The `-Wall` flag shows any warnings during compilation.

### Step 4: Run The Program

```bash
./faculty_module.exe
```

You should now see the Faculty Menu on screen.

---

## 🖥️ Using The Menu

Once the program starts, you will see this menu:

```
****Faculty Menu****
0. Exit the programme
1. Create Faculty
2. Insert Faculty At Any Position
3. Delete Faculty At Any Position
4. Search Faculty
5. Modify Faculty
6. Display List for Faculty

Enter your choice:
```

Just type a number and press **Enter** to pick an option. Follow the prompts to enter faculty details.

---

## 📝 Important Notes

- You must **create at least one faculty (option 1)** before using insert, delete, search, or modify.
- When entering designation, type a number from **1 to 5**.
- When entering department, use the **department codes** listed in the table above (e.g., `10` for CSE).
- Choosing **option 0** to exit will properly free all memory — always exit this way instead of force-closing.

---

## 🛠️ Requirements

- [MSYS2](https://www.msys2.org/) installed with the UCRT64 environment
- GCC compiler (comes with MSYS2)
- Windows OS

---

## 🎯 Project Assumptions

- All inputs (Name, Address, Phone Number) are entered as text strings.
- Designation must be a **positive integer between 1 and 5**.
- Department must be one of the **valid department codes** (10–16, 20–24, 30–31).
- The linked list grows **dynamically** — there is no fixed limit on the number of faculty records.
- Memory is properly freed only when you **exit using option 0**.

---

## 🤝 Contributing

If you have any suggestions or want to improve the project, feel free to fork it, make your changes and submit a pull request.

---

## 🔒 License

This project is licensed under the [**MIT License**](https://opensource.org/licenses/MIT).

---

## 📬 Contact

If you have any questions or concerns, please don't hesitate to contact me via email at [imam220826@gmail.com](mailto:imam220826@gmail.com)
