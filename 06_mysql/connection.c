#include <stdio.h>
#include <mysql/mysql.h>

int main(int argc, char *argv[]){
    //  MYSQL CONNETION
    MYSQL *conn;
    
    //  initlizing connection
    conn = mysql_init(0);

    //  connecting to db
    if(!(mysql_real_connect(conn, "localhost", "admin", "admin", "scanner_db", 0, NULL, 0))){
        printf("Error while connecting to db\nNo, database exits!");
        mysql_close(conn);
        return -1;
    }

    printf("Connection was estatblist..");
    mysql_close(conn);
    return 0;
}
    
