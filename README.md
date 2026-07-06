
# Student Gradebook & Result Analyzer

A simple C++ console application for managing student marks, calculating GPA, ranking students, and generating performance reports.

## Project Structure

- `Project/new.cpp` - Main C++ source file containing the gradebook application.
- `Project/student.txt` - Sample data file used to store student records.

## Features

- Load student records from a data file
- Add new student records
- Search student records by ID
- Update existing student marks
- View all student records in a formatted table
- Calculate GPA for all students
- Rank students based on total marks
- Generate a performance report with average GPA, pass/fail count, and topper details

## How to Compile

Use a C++ compiler such as `g++` or Visual Studio tools.

Example with MinGW:

```sh
g++ Project/new.cpp -o Project/new.exe
```

## How to Run

Open a terminal or command prompt inside the repository and run:

```sh
Project\new.exe
```

If you compile from source:

```sh
./Project/new.exe
```

## Notes

- The application reads and writes student records from `Project/student.txt`.
- Each student record includes an ID, first name, surname, marks for 5 subjects, total marks, and GPA.
- After adding or updating records, use the GPA calculation option to refresh GPA values.

## Recommended GitHub Usage

- Add `README.md` to the repository root so GitHub displays the project summary.
- Track `Project/new.cpp` and `Project/student.txt` as source and sample data files.
