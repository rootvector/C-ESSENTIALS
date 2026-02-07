#include <mysql/mysql.h>
#include <stdio.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);

    if (conn == NULL) {
        printf("mysql_init() failed\n");
        return 1;
    }

    if (mysql_real_connect(
            conn,
            "localhost",   // host
            "root",        // username
            "kali",    // password
            "school_db",      // database name
            3306, NULL, 0) == NULL) {

        printf("Connection Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    if (mysql_query(conn, "SELECT * FROM persons")) {
        printf("Query Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    res = mysql_store_result(conn);

    while ((row = mysql_fetch_row(res))) {
        printf("ID: %s | Name: %s\n", row[0], row[1]);
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}

