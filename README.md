# 🎓 University Course Registration System (C++)

## 📌 Project Overview
This project is a **console-based University Course Registration System** developed in **C++** using core concepts of **Data Structures and Object-Oriented Programming (OOP)**.

The system allows a student to enroll in courses while ensuring that all **prerequisites are satisfied**. Courses and their dependencies are modeled using a **graph (Adjacency Matrix)**.

---

## 🚀 Features
- 📚 View available courses and their prerequisites  
- ✅ Enroll in courses after prerequisite validation  
- 🎓 Track enrolled courses for a student  
- 🔍 Check course completion before enrollment  
- 🧩 Graph-based prerequisite management  
- 💻 Menu-driven interactive interface  

---

## 🧠 Concepts Used
- **Object-Oriented Programming (OOP)**
  - Inheritance
  - Polymorphism (Virtual Functions)
  - Encapsulation

- **Data Structures**
  - Graph (Adjacency Matrix)
  - Arrays

- **Algorithms**
  - Linear Search
  - Validation Logic for prerequisites  

---

## ⚙️ How It Works
- Courses are stored in an array.
- Prerequisites are represented using an **Adjacency Matrix**.
- Before enrolling in a course, the system:
  1. Checks all prerequisite courses
  2. Verifies if the student has completed them
  3. Allows or denies enrollment accordingly

---

## 🖥️ Sample Output
 University Course Registration System =====
1. View Courses
2. Enroll in Course
3. View Student Details
0. Exit
Enter choice: 2
Enter course name: zainab
Prerequisites not satisfied.

===== University Course Registration System =====
1. View Courses
2. Enroll in Course
3. View Student Details
0. Exit
Enter choice: 1

--- Available Courses & Prerequisites ---
Programming-I <- None
Data Structures <- Programming-I
Algorithms <- Data Structures
Databases <- Programming-I

===== University Course Registration System =====
1. View Courses
2. Enroll in Course
3. View Student Details
0. Exit
Enter choice: 0
Exiting system...

--------------------------------
Process exited after 25.34 seconds with return value 0
Press any key to continue . . .

