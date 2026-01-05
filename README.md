# 🎓 Student Record Management System (C Project)

A **console-based Student Record Management System** built in **C** that performs CRUD operations using a **CSV file** for persistent storage.  
This project is ideal for **students and beginners** to understand file handling, structures, and real-world data management in C.

---

## 📌 Project Overview

The **Student Record Management System** allows users to:

- Add new student records
- View all students
- Search a student by ID
- Update existing student records
- Delete student records
- Generate analytical reports (average, highest, lowest marks, pass/fail count)

All data is stored in a CSV file (`student.csv`) to simulate a lightweight database.

---

## 🛠️ Technologies Used

- **Programming Language:** C  
- **Storage:** CSV file (`student.csv`)  
- **Concepts Covered:**
  - Structures
  - File handling
  - Input validation
  - Modular programming
  - CRUD operations
  - Basic data analysis

---

## 📂 Project Structure

```
Student-Record-Management-System/
│
├── main.c # Source code
├── student.csv # Data storage file
└── README.md # Project documentation
```

---

## 📄 student.csv Format

The CSV file must exist in the same directory as the program.

id,name,course,marks,grade


### Example:

- 101,John Doe,Computer Science,85,B
- 102,Alice Smith,Mathematics,92,A

---

## ⚙️ Features

### ✅ Add Student
- Ensures **unique student ID**
- Automatically calculates **grade**

### 👀 View Students
- Displays all records in a tabular format

### 🔍 Search Student
- Search by **Student ID**

### ✏️ Update Student
- Modify name, course, marks, and grade

### ❌ Delete Student
- Remove a student record permanently

### 📊 Generate Report
- Total students
- Average marks
- Highest & lowest marks
- Pass & fail count

---

## 🧮 Grade Criteria

| Marks Range | Grade |
|------------|-------|
| ≥ 90       | A     |
| ≥ 75       | B     |
| ≥ 50       | C     |
| ≥ 35       | D     |
| < 35       | F     |

---

## ▶️ How to Compile and Run

### Compile
```bash
    gcc main.c -o student_management
```
### Run
```bash
    ./student_management
```

---

### 📸 Sample Menu
--- Student Record Management System ---
1. Add Student
2. View Students
3. Search Student
4. Update Student
5. Delete Student
6. Generate Report
0. Exit

---

## ⚠️ Important Notes

- Ensure student.csv exists before running program

- Do not delete the header row in the CSV file

- The program uses a temporary file (temp.csv) during update and delete operations

---

## 🎯 Learning Outcomes

- Practical understanding of file handling in C

- Real-world usage of structures

- Implementation of CRUD operations

- Experience with CSV-based data storage

- Improved logical thinking and program design

---

## 🚀 Future Enhancements

- Sorting students by marks or name

- Export reports to a separate file

- Password-protected access

- GUI version

- Database integration (MySQL / SQLite)

---

## 👨‍💻 Author

**Tanuj Kumar**
B.Tech CSE Student
Cybersecurity & Systems Enthusiast

---

## ⭐ Support

If you find this project helpful:

- ⭐ Star this repository

- 🍴 Fork it

- 🧠 Use it for learning and improvement

**Happy Coding!** 🚀





