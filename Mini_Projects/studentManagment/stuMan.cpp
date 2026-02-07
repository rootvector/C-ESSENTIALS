#include <iostream>
#include <string>
#include <limits>
#include <mariadb/mysql.h> // Changed for Kali/Linux compatibility
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

class Student : public Person {
public:
    int rollno;
    double mobileno;
    string section;

    void setdata() {
        Person::setdata(); 
        cout << "[+] Roll No: "; cin >> rollno;
        cout << "[+] Mobile No: "; cin >> mobileno;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[+] Section: "; getline(cin, section);
    }
};

class DBManager {
    MYSQL* conn;
public:
    DBManager() {
        conn = mysql_init(0);
        
        // KALI LINUX CONNECTION SETUP:
        // Host: "localhost"
        // User: "root"
        // Password: Use the password you set during mariadb-secure-installation
        // Port: 3306
        if (mysql_real_connect(conn, "localhost", "root", "your_password_here", NULL, 3306, NULL, 0)) {
            
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
            cout << "[ERROR] Connection Failed: " << mysql_error(conn) << endl;
        }
    }

    void saveStudent(Student& s) {
        if (!conn) return;

        // Note: In real apps, use mysql_real_escape_string to prevent SQL Injection
        stringstream q1;
        q1 << "INSERT INTO persons (name, department, course, cyear, identity) VALUES ('"
           << s.name << "', '" << s.department << "', '" << s.course << "', " << s.cyear << ", '" << s.identity << "')";
        mysql_query(conn, q1.str().c_str());
        
        int p_id = mysql_insert_id(conn);

        stringstream q2;
        q2 << "INSERT INTO students (person_id, rollno, mobileno, section) VALUES ("
           << p_id << ", " << s.rollno << ", " << s.mobileno << ", '" << s.section << "')";

        if (mysql_query(conn, q2.str().c_str()) == 0) {
            cout << "\n[SUCCESS] Record saved to Kali MariaDB!" << endl;
        }
    }

    ~DBManager() { if(conn) mysql_close(conn); }
};

int main() {
    system("clear"); // Changed from 'cls' to 'clear' for Linux
    cout << "========================================" << endl;
    cout << "   KALI STUDENT DATABASE SYSTEM (SQL)   " << endl;
    cout << "========================================" << endl;

    Student s;
    DBManager db;

    s.setdata();
    db.saveStudent(s);

    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}
