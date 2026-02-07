#include <stdio.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *conn;

    // Initialize MySQL object
    conn = mysql_init(NULL);
    if(conn == NULL) {
        printf("MySql init failed\n");
        return 0;
    }

    //Connect to database
    if(mysql_real_connect(
                conn,
                "localhost",    //host
                "admin",        //user
                "admin",        // Password
                "studentManagment", //database
                3306,               //port
                NULL,
                0) == NULL){
        printf("Connection failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    printf("Connected to MariaDB successfully!\n");

    // Close Connecton
    mysql_close(conn);
    return 0;
}
