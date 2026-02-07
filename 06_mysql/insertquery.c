#include <stdio.h>
#include <mysql/mysql.h>

int main(int argc, char *argv[]){
    MYSQL *conn;
    conn = mysql_init(NULL);

    //query 
    const char *query = "INSERT INTO Scans(target, port, status) VALUES('192.168.1.4', 22, 'OPEN')";

    //conncting to db
    if(!(mysql_real_connect(conn, "localhost", "admin", "admin", "scanner_db", 0, NULL, 0))){
        printf("Connection Error");
        mysql_close(conn);
        return -1;
    }
    //  running query
    if((mysql_query(conn, query))){
            printf("Insertion error");
    }
    printf("DATA inserted successfully!");
    mysql_close(conn);
    return 0;
}
