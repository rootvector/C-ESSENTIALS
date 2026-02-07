#include <stdio.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);
    if (!conn) {
        printf("mysql_init failed\n");
        return -1;
    }

    if (!mysql_real_connect(conn, "localhost", "admin", "admin",
                             "scanner_db", 0, NULL, 0)) {
        printf("Connection Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;
    }

    const char *query = "SELECT target, port FROM Scans";

    if (mysql_query(conn, query)) {
        printf("Query Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;
    }

    res = mysql_store_result(conn);
    if (!res) {
        printf("Result Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;
    }

    while ((row = mysql_fetch_row(res))) {
        printf("TARGET %s | PORT %s\n", row[0], row[1]);
    }

    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}

