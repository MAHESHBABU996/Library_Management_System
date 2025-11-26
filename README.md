# Library_Management_System
📚 Library Management System

📝 Project Overview

The Library Management System is a C-based console application designed to manage books in a library.
It allows librarians or users to:

Add new books

Display all books

Search books

Issue and return books

Delete books

Store data permanently using file handling

The project uses structures, file operations, and modular programming, making it perfect for academic mini projects.

🚀 Key Features
✅ 1. Add Book

Allows entering:

Book ID

Title

Author

Quantity

The system stores book data permanently in library.dat.

✅ 2. Display All Books

Shows a formatted list of all books with:

Book ID

Title

Author

Quantity

Number of copies issued

✅ 3. Search Book

Search any book by Book ID and view complete details.

✅ 4. Issue Book

Issues a book only if available

Automatically updates number of issued copies

✅ 5. Return Book

Decreases issued count

Helps maintain correct inventory

✅ 6. Delete Book

Remove a book permanently using its ID.
A temporary file method ensures safe record deletion.

✅ 7. File Handling (Permanent Storage)

All data is saved in:

library.dat


Closing the program will not erase the records.

🛠 Technologies Used

C Programming Language

File Handling (Binary Files)

Structured Programming

Console-based UI

📂 Project Structure
/LibraryManagementSystem
   ├── library.c           # Main source code
   ├── library.dat         # Database file (auto-created)
   ├── README.md           # Documentation
   └── screenshots/        # Optional

📌 Book Structure

Each book contains:

Field	Description
id	Unique Book ID
title	Book Title
author	Author Name
quantity	Total Copies
issued	Number of Issued Copies
▶️ How to Run
Terminal / CMD / CodeBlocks / DevC++
gcc library.c -o library
./library

📘 Sample Menu
======================================
      LIBRARY MANAGEMENT SYSTEM
======================================
1. Add Book
2. Display All Books
3. Search Book
4. Issue Book
5. Return Book
6. Delete Book
7. Exit
Enter your choice:

🌟 Why This Project is Good

✔ Demonstrates file handling
✔ Includes CRUD operations
✔ Clean and modular functions
✔ User-friendly console interface
✔ Perfect for college submissions
✔ Enhancable into a full library system


Author : Mahesh Babu Baswani
