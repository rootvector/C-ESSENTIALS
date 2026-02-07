# cpp-projects

This repository contains simple C and C++ projects created for fun and upskilling in C/C++ programming.  
Each source file implements basic functionality demonstrating typical console input/output programs and fundamental programming constructs.

## Projects Included

### 1. `studentmanagment.cpp`

A C++ console application to **manage student data** (record, display, search, etc.).  
It illustrates use of standard input/output and basic C++ logic.

### 2. `fetchstudentdata.c`

A C program that fetches student data from standard input and displays it.  
This shows C-style I/O (`scanf`/`printf`) and working with simple structs/arrays.

## How to Compile and Run

These programs are intended to be compiled with a C/C++ compiler (e.g., `g++` for C++, `gcc` for C).

### Compile C++ Program

```bash
g++ studentmanagment.cpp -o studentmanagment
```

Then run:

```bash
./studentmanagment
```
If having [ERROR] Connection Failed: Access denied for user 'root'@'localhost'
Then Run with sudo:
```bash
sudo ./studentmanagment
```
### Compile C Program

```bash
gcc fetchstudentdata.c -o fetchstudentdata
```

Then run:

```bash
./fetchstudentdata
```

## Git Commands Used in this Repository

The following list summarizes the Git commands commonly used during development:

### Stage changes
```bash
git add filename
```
Use this to add modified/new files to the staging area before committing.

### Commit staged changes
```bash
git commit -m "Your descriptive message"
```
Creates a new commit with staged updates.

### Remove file from staging (if added accidentally)
```bash
git reset HEAD filename
```
This **unstages** the file but keeps it on disk.

### Remove file from repo and disk
```bash
git rm filename
git commit -m "Remove filename"
```

### Remove file only from Git (keep it locally)
```bash
git rm --cached filename
git commit -m "Stop tracking filename"
```

## Repository Structure

```
/
├── studentmanagment.cpp    # C++ student management program
├── fetchstudentdata.c      # C program to fetch student data
└── README.md               # This file
```

## Contribution

Feel free to fork the repository and add your own C/C++ projects.  
Pull requests are welcome to enhance code quality, add documentation, or include new examples.

---


