#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define LOCALHOST "localhost"
#define USER "test"
#define PASSWORD "test" // TODO: Salt and hash the password
#define DATABASE "lieblingsKfz"
#define TABLE "pkw"

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void connect_to_database(MYSQL **con)
{
    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(*con, LOCALHOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL)
    {
        finish_with_error(*con);
    }
}

void get_user_input(char *marke, char *typ, int *baujahr)
{
    printf("Enter Marke: ");
    fgets(marke, 16, stdin);
    marke[strcspn(marke, "\n")] = '\0'; // Remove newline character

    printf("Enter Typ: ");
    fgets(typ, 16, stdin);
    typ[strcspn(typ, "\n")] = '\0'; // Remove newline character

    char baujahr_str[5];
    printf("Enter Baujahr: ");
    fgets(baujahr_str, sizeof(baujahr_str), stdin);
    *baujahr = atoi(baujahr_str);
}

void add_row(char *table)
{
    // Initialize MySQL connection
    MYSQL *con = mysql_init(NULL);
    char query[256];

    // Variables to store user input
    char marke[16];
    char typ[16];
    int baujahr;

    // Get user input for the new row
    get_user_input(marke, typ, &baujahr);

    // Create the SQL query to insert the new row
    snprintf(query, sizeof(query), "INSERT INTO `%s`(`lfdNr`, `marke`, `typ`, `bauJahr`) VALUES(NULL, '%s', '%s', %d);", table, marke, typ, baujahr);

    // Connect to the database
    connect_to_database(&con);

    // Execute the query
    if (mysql_query(con, query))
    {
        // If the query fails, print the error and exit
        finish_with_error(con);
    }

    // Close the database connection
    mysql_close(con);

    // Print success message
    printf("Row added to the table '%s' successfully!\n", table);
}

// Function to test the connection to the database
bool test_con_database(MYSQL *con)
{
    bool success = true;

    // Connect to the database
    connect_to_database(&con);
    // Close the connection
    mysql_close(con);

    return success;
}

void read_all_rows(char *table)
{
    // Initialize MySQL connection
    MYSQL *con = mysql_init(NULL);
    MYSQL_RES *result;
    MYSQL_ROW row;
    char query[256];

    // Create the SQL query to select all rows
    snprintf(query, sizeof(query), "SELECT * FROM `%s`;", table);

    // Connect to the database
    connect_to_database(&con);

    // Execute the query
    if (mysql_query(con, query))
    {
        // If the query fails, print the error and exit
        finish_with_error(con);
    }

    // Store the result of the query
    result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con);
    }

    // Get the number of fields in the result
    int num_fields = mysql_num_fields(result);

    // Print the rows
    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            if (row[i])
            {
                printf("%s ", row[i]);
            }
            else
            {
                printf("NULL ");
            }
        }
        printf("\n");
    }

    // Free the result
    mysql_free_result(result);

    // Close the database connection
    mysql_close(con);
}

int main()
{
    MYSQL *con = mysql_init(NULL);
    int choice;
    char choice_str[3];

    if(test_con_database(con))
    {
        printf("Connection to the database successful!\n");
    }
    else
    {
        printf("Connection to the database failed!\n");
        return 0;
    }

    while(true)
    {
        printf("Choose an option:\n");
        printf("1. Add a row\n");
        printf("2. Read all rows\n");
        printf("Enter your choice: ");

        fgets(choice_str, sizeof(choice_str), stdin);
        choice = atoi(choice_str);

        switch (choice)
        {
        case 1:
            add_row(TABLE);
            break;
        case 2:
            read_all_rows(TABLE);
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }

    return 0;
}