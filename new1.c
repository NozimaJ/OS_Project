

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>

int main() {
   MYSQL *conn;
   MYSQL_RES *res=NULL;
   MYSQL_ROW row;
   char q[1024];
/*   char del_name[1024];
   char in_name[1024];
   char up_name[1024];
   int id;
*/
   char *server = "localhost";
   char *user = "os";
   char *password = "12345@oS";  
   char *database = "new";
   conn = mysql_init(NULL);
   
   // Connect to database
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }


//DISPLAY
   if (mysql_query(conn, "SELECT * FROM users_table;")) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   res = mysql_use_result(conn);

   printf("MySQL Tables in mysql database:\n");
   while ((row = mysql_fetch_row(res)) != NULL)
   printf("%s: %s: %s: %s: %s: %s: %s: %s  \n", row[0],row[1], row[2],row[3], row[4],row[5], row[6],row[7]);

//DISPLAY2
   if (mysql_query(conn, "SELECT * FROM hotel_table;")) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   res = mysql_use_result(conn);

   printf("MySQL Tables in mysql database:\n");
   while ((row = mysql_fetch_row(res)) != NULL)
   printf("%s: %s: %s: %s: %s: %s: %s: %s  \n", row[0],row[1], row[2],row[3], row[4],row[5], row[6],row[7]);
//NEW USER ID AND NAME IS INSERTED.
//FIRST ENTER NEW USER ID
//SECONDLY ENTER NEW USER NAME
/*
  printf( "ENTER NEW INSERT ID :");
  scanf("%d", &id);

  printf( "ENTER NEW INSERT NAME :");
  scanf("%s", in_name);

//INSERT PROCESS
sprintf(q, "INSERT INTO test(id, name) VALUES('%d', \'%s\')", id, in_name);
printf("%s\n",q);
if(mysql_query(conn, q))
{
	mysql_error(conn);
	return 0;
}else{
	return 1;
}


//USER IS DELETING WITH HIS/HER NAME
//ENTER DELETED USER NAME

   printf( "ENTER NAME :");
   scanf("%s", del_name);

//DELETE PROCESS
  sprintf(q,"DELETE  FROM test WHERE name=\'%s\' ", del_name);
  printf("%s\n", q);
  if (mysql_query(conn,q))
  { 
      mysql_error(conn);
    return 0;  
  }else
    {  
      return 1;
    }


//MODIFY WITH ALREADY EXIST USER HIS/HER NEW ID WITH HIS/HER CURRENT USER NAME

  printf( "ENTER NEW ID OF UPDATED:");
  scanf("%d", &id);

  printf( "Enter new id from which name :");
  scanf("%s", up_name);

//UPDATE PROCESS
  sprintf(q,"UPDATE test SET id=%d WHERE name=\'%s\' ", id, up_name);
  printf("%s\n", q);
  if (mysql_query(conn,q))
  { 
      mysql_error(conn);
    return 0;  
  }else
    {  
      return 1;
    }

*/
// CLOSE CONNECTION 
   mysql_free_result(res);
   mysql_close(conn);
}
