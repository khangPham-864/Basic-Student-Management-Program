# Basic Student Management Program

## Project Overview

This project implements a basic **Student Management System** using C++.

The program manages two types of students:

- University students
- College students

Each student type has different course structures, including different numbers of semesters, courses, assignments, tests, and exams.

The project focuses on applying object-oriented programming and modern C++ features to make the program easier to manage, extend, and maintain.

The main goals of this project are to:

- Manage student information through a command-line interface
- Support different student types using inheritance and polymorphism
- Store university and college students in one shared student list
- Use modern C++ memory management with `unique_ptr`
- Apply Singleton and Factory-style design inside the `University` class
- Improve readability and safety using `vector`, `auto`, range-for loops, and lambda expressions

---

## Tech Stack

- C++
- Standard Template Library
- Object-Oriented Programming
- Smart Pointers
- `std::vector`
- `std::unique_ptr`
- `std::make_unique`
- Range-based for loops
- `auto`
- Lambda expressions
- Singleton Pattern
- Factory-style object creation

---

## Problems

The project solves several common problems in a basic student management system.

### 1. Managing Different Student Types

University students and college students have different study structures.

For example:

- `UniStudent` has 8 semesters and 4 courses per semester
- `CollegeStudent` has 4 semesters and 3 courses per semester
- Each type also has different numbers of assignments, tests, and exams

Because of this, storing every student in the same way without proper abstraction would make the code harder to manage.

---

### 2. Avoiding Duplicated and Unorganized Data

Each student type needs information about:

- Number of assignments
- Number of tests
- Number of exams

Instead of declaring these values as separate variables everywhere, the program groups them into one struct.

---

### 3. Managing Dynamic Student Lists Safely

A university can contain many students, and the number of students can change while the program runs.

Using raw dynamic arrays would make memory management harder and could increase the risk of:

- Memory leaks
- Buffer overflows
- Dangling pointers
- Manual resizing errors

---

### 4. Keeping One Main University Manager

The `University` class is responsible for managing all students.

The program needs one consistent university object so that student information is stored and modified in one place.

---

### 5. Making Student Creation Easier

The program needs to create either a `UniStudent` or a `CollegeStudent` based on the user’s selected student type.

Without a central creation method, the main function would need to know too much about how each student object is created.

---

## How This Code Solves the Problems

The project solves these problems using object-oriented design and modern C++ features.

### 1. Inheritance and Polymorphism

The program uses an abstract-style base class:

```cpp
class Student
```

Then two derived classes inherit from it:

```cpp
class UniStudent : public Student
class CollegeStudent : public Student
```

This allows both student types to be stored together as `Student` objects while still keeping their own specific behaviour.

---

### 2. Struct for Course Requirements

The program uses a struct called `including`:

```cpp
struct including {
    int assignments;
    int tests;
    int exams;
};
```

This groups related course requirement values together.

For example:

```cpp
struct including includ { 3, 2, 1 };
```

This means a university student has:

- 3 assignments
- 2 tests
- 1 exam

College students use a different structure:

```cpp
struct including includ { 1, 1, 1 };
```

This makes the code more organized and easier to understand.

---

### 3. `vector<unique_ptr<Student>>` for Student Storage

The `University` class stores students using:

```cpp
vector<unique_ptr<Student>> students;
```

This allows the program to store both `UniStudent` and `CollegeStudent` objects in the same list.

Using `vector` helps with:

- Dynamic resizing
- Adding students
- Removing students
- Iterating through the list

Using `unique_ptr` helps with:

- Automatic memory management
- Preventing memory leaks
- Preventing dangling pointer issues
- Making ownership of each student object clear

---

### 4. Singleton Pattern for University Management

The `University` class uses the Singleton Pattern.

The constructor is private:

```cpp
University(string name, int size)
```

The program creates or accesses the university instance through:

```cpp
static University* getInstance(string name, int size)
```

This ensures that only one `University` object is created and used throughout the program.

The class also disables copying:

```cpp
University(const University&) = delete;
University& operator=(const University&) = delete;
```

This prevents another `University` object from being copied or assigned accidentally.

---

### 5. Factory-Style Student Creation

The `University` class creates student objects inside the `add()` function.

Depending on the student type, it creates either:

```cpp
make_unique<UniStudent>(...)
```

or:

```cpp
make_unique<CollegeStudent>(...)
```

This keeps the creation logic inside the `University` class instead of spreading it across the main program.

The result is cleaner and easier to manage.

---

## Key Features

### Add Students

The user can add a new student by entering:

- Student name
- Day of birth
- Course name
- Student type

Student type can be:

```txt
1: Uni
2: College
```

The program then creates the correct student object and stores it in the university list.

---

### Display All Students

The program can display all students currently stored in the university.

Displayed information includes:

- Name
- Day of birth
- Course name
- Student type
- Final score

---

### Remove Student by Name

The program allows the user to remove a student by entering their name.

The program searches through the student list using `find_if()` and a lambda expression:

```cpp
auto it = find_if(students.begin(), students.end(),
    [&](const unique_ptr<Student>& student) {
        return student->name == name;
    });
```

If the student is found, the program removes that student from the list.

If not, it prints:

```txt
Cannot find a student with that name!!
```

---

### Display Best-Performing Student

The program can find the highest score in the student list.

It then displays every student whose score matches that highest score.

This means if multiple students have the same best score, all of them will be shown.

---

### Capacity Control

The university has a maximum capacity.

If the user tries to add more students than the capacity allows, the program prints:

```txt
The list is full!!
```

---

## Program Structure

```txt
Basic-Student-Management-Program
│
├── Source.cpp
└── README.md
```

The main source file contains:

```txt
Library imports
StudentType enum
including struct
Student base class
UniStudent class
CollegeStudent class
University class
main function
```

---

## Main Classes

### `Student`

The base class for all students.

It stores shared student information:

- `name`
- `score`
- `day_of_birth`
- `school_name`
- `course_name`
- `studentType`

It also defines virtual methods:

```cpp
DoAssignment()
TakeTest()
TakeExam()
```

These methods allow derived student classes to define their own scoring process.

---

### `UniStudent`

Represents a university student.

A university student has:

```txt
8 semesters
4 courses per semester
3 assignments
2 tests
1 exam
```

This class implements its own versions of:

```cpp
DoAssignment()
TakeTest()
TakeExam()
```

---

### `CollegeStudent`

Represents a college student.

A college student has:

```txt
4 semesters
3 courses per semester
1 assignment
1 test
1 exam
```

This class also implements its own versions of:

```cpp
DoAssignment()
TakeTest()
TakeExam()
```

---

### `University`

The main management class.

It stores:

```cpp
string name;
vector<unique_ptr<Student>> students;
int capacity;
int count;
```

It supports:

```cpp
add()
display()
remove()
bestScore()
getInstance()
```

The class is designed as a Singleton and also works as the object creator for different student types.

---

## How to Use the Program

### 1. Install a C++ Compiler

Make sure you have a C++ compiler installed.

Examples:

- g++
- MinGW
- MSVC

---

### 2. Open the Project

Open the project in VS Code or another C++ IDE.

---

### 3. Compile the Program

Using g++:

```bash
g++ Source.cpp -o student_management
```

---

### 4. Run the Program

On Windows:

```bash
student_management.exe
```

On macOS/Linux:

```bash
./student_management
```

---

## Program Menu

When the program runs, it asks for:

```txt
Enter name of university
Enter capacity of list of students
```

Then it shows this menu:

```txt
1: add new student
2: display list
3: remove student
4: display best students
0: exit
```

---

## Example Usage

```txt
Enter name of university (no space between words): UQ
Enter capacity of list of students: 3

Enter choice (1: add new student, 2: display list, 3: remove student, 4: display best students 0: exit): 1

Please enter details of the new student to be added:
Name: John Smith
Day of birth: 01/01/2004
Course: Software Engineering
Is he/she a university or college student? (1: Uni, 2: College): 1
```

Then the student is added to the university list.

---

## Main Program Flow

```txt
Start

Enter university name

Enter university capacity

Create University instance

Show menu

If choice is 1:
    Enter student details
    Enter student type
    Add student to list

If choice is 2:
    Display all students

If choice is 3:
    Enter student name
    Search for matching student
    Remove student if found

If choice is 4:
    Find highest score
    Display best student(s)

If choice is 0:
    Exit program

Otherwise:
    Print invalid number message
```

---

## Modern C++ Features Used

### Smart Pointer

The program uses:

```cpp
unique_ptr<Student>
```

This makes memory management safer because each student object has one clear owner.

---

### `make_unique`

The program creates student objects using:

```cpp
make_unique<UniStudent>()
make_unique<CollegeStudent>()
```

This avoids direct use of `new` when creating student objects.

---

### Range-Based For Loop

The program uses range-for loops to display and search through students:

```cpp
for (const auto& student : students)
```

This makes the code shorter, cleaner, and less likely to have loop boundary errors.

---

### `auto`

The program uses `auto` to simplify complex types.

Example:

```cpp
auto it = find_if(...)
```

This avoids manually writing long iterator types.

---

### Lambda Expression

The program uses a lambda expression to search for a student by name:

```cpp
[&](const unique_ptr<Student>& student) {
    return student->name == name;
}
```

This keeps the search condition close to the code that uses it.

---

## What I Learned

Through this project, I learned how to apply C++ object-oriented programming and modern C++ features in a student management system.

The project helped me understand:

- How inheritance can represent different student types
- How polymorphism allows different objects to be managed through one base type
- How `vector` is safer and more flexible than manual dynamic arrays
- How `unique_ptr` helps manage memory automatically
- How the Singleton Pattern keeps one central university manager
- How Factory-style object creation simplifies the main program
- How range-for loops, `auto`, and lambda expressions make code cleaner

---

## Future Improvements

Possible improvements for the project include:

- Add stronger input validation
- Connect score input directly into the main menu
- Add file saving and loading
- Add search by course or student type
- Add editing student information
- Improve memory cleanup for the Singleton instance
- Add unit tests
- Split the program into header and implementation files

---

## Credits

This is an individual project.

Author:

```txt
Pham Le Nguyen Khang
```

---

## Summary

This project is a C++ student management system that demonstrates object-oriented programming and modern C++ design.

It supports university and college students, stores them through a shared base class, manages them inside a singleton `University` class, and uses modern features such as `vector`, `unique_ptr`, range-for loops, `auto`, and lambda expressions to improve readability, safety, and maintainability.
