# Basic-Student-Management-Program
This project implements a student management system using C++. It allows for the creation, management, and evaluation of both university and college students based on their scores in assignments, tests, and exams. It features object-oriented programming practices including inheritance, polymorphism, and the singleton pattern for university management.

**Tech Stack**
- C++
- Standard Template Library
- Object-Oriented Programming (OOP)

**Key Features**
Support for University and College students with different grading schemes:
- Modular Classes:
  + Student (abstract base class)
  + UniStudent and CollegeStudent (derived classes)
- Score Evaluation:
  + Dynamic input of assignment, test, and exam scores
  + Calculates final scores based on course/semester structure
- University Singleton:
  + Only one instance of a University can exist (singleton pattern)
  + Manages a dynamic list of students using std::vector and unique_ptr
- CLI Interface:
  + Add students
  + Display all students
  + Remove a student by name
  + Display best-performing student(s)

**How to run**
1. Ensure VS Code and C++ compiler installed.
2. Install C++ Extension for VS Code.
3. Download and run Source.cpp file in VS Code.
