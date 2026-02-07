#include <iostream>
#include <string>
#include <limits>
#include <mysql/mysql.h>
#include <sstream>

using namespace std;

// --- Parent Class ---
class Person {
public:
    int cyear;
    string name, department, course, identity;

    void setdata() {
        cout << "\n--- Enter Person's Information ---" << endl;
        cout << "[+] Name: "; getline(cin, name);
        cout << "[+] Department: "; getline(cin, department);
        cout << "[+] Course: "; getline(cin, course);
        cout << "[+] Year: "; cin >> cyear;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[+] Identity: "; getline(cin, identity);
    }
};

// --- Child Class (Inheritance) ---
class Student : public Person {
public:
    int rollno;
    double mobileno;
    string section;

    void setdata() {
        Person::setdata(); // Call Parent setup
        cout << "[+] Roll No: "; cin >> rollno;
        cout << "[+] Mobile No: "; cin >> mobileno;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[+] Section: "; getline(cin, section);
    }
};

// --- Professional Database Handler ---
class DBManager {
    MYSQL* conn;
public:
    DBManager() {
        conn = mysql_init(0);
        // 1. Connect to Local XAMPP MySQL
        if (mysql_real_connect(conn, "localhost", "root", "kali", NULL, 3306, NULL, 0)) {
            
            // 2. Auto-Create Database and Tables
            mysql_query(conn, "CREATE DATABASE IF NOT EXISTS school_db");
            mysql_select_db(conn, "school_db");

            mysql_query(conn, "CREATE TABLE IF NOT EXISTS persons ("
                              "id INT AUTO_INCREMENT PRIMARY KEY, "
                              "name VARCHAR(100), department VARCHAR(100), "
                              "course VARCHAR(100), cyear INT, identity VARCHAR(100))");

            mysql_query(conn, "CREATE TABLE IF NOT EXISTS students ("
                              "id INT AUTO_INCREMENT PRIMARY KEY, "
                              "person_id INT, rollno INT, mobileno DOUBLE, "
                              "section VARCHAR(10), FOREIGN KEY (person_id) REFERENCES persons(id) ON DELETE CASCADE)");
            
            cout << "[SYSTEM] Database Engine Ready." << endl;
        } else {
            cout << "[ERROR] Could not connect to MySQL. Is XAMPP running?" << endl;
        }
    }

    void saveStudent(Student& s) {
        if (!conn) return;

        // Insert into Persons
        stringstream q1;
        q1 << "INSERT INTO persons (name, department, course, cyear, identity) VALUES ('"
           << s.name << "', '" << s.department << "', '" << s.course << "', " << s.cyear << ", '" << s.identity << "')";
        mysql_query(conn, q1.str().c_str());
        
        int p_id = mysql_insert_id(conn);

        // Insert into Students
        stringstream q2;
        q2 << "INSERT INTO students (person_id, rollno, mobileno, section) VALUES ("
           << p_id << ", " << s.rollno << ", " << s.mobileno << ", '" << s.section << "')";

        if (mysql_query(conn, q2.str().c_str()) == 0) {
            cout << "\n[SUCCESS] Record saved to MySQL database!" << endl;
        }
    }

    ~DBManager() { mysql_close(conn); }
};

int main() {
    system("cls"); // Clear screen for Windows
    cout << "========================================" << endl;
    cout << "   STUDENT DATABASE MANAGEMENT SYSTEM   " << endl;
    cout << "========================================" << endl;

    Student s;
    DBManager db;

    s.setdata();
    db.saveStudent(s);

    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}
