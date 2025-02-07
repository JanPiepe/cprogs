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

typedef struct Login_info
{
    bool usesLogin;  // if true we ask for login info, if false we use the default login info.
    bool isLoggedIn; // if true we are logged in. And more options are available.
    char username[256];
    char password[256];
} login_info;

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void endProgram(MYSQL *con, login_info *login_info)
{
    free(login_info);
    mysql_close(con);
    exit(0);
}

void dbContact(MYSQL **con, login_info **login_info)
{
    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        endProgram(*con, *login_info);
    }

    // Login with the given login info.
    if((*login_info)->usesLogin)
    {
        if (mysql_real_connect(*con, LOCALHOST, (*login_info)->username, (*login_info)->password, DATABASE, 0, NULL, 0) == NULL)
        {
            finish_with_error(*con);
        }
    }
    else // Login with default login info. For lazy devs.
    {
        if (mysql_real_connect(*con, LOCALHOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL)
        {
            finish_with_error(*con);
        }
    }
}

void get_user_input(char *marke, char *typ, int *baujahr)
{
    printf("Enter Marke: ");
    fgets(marke, 16, stdin);

    // We access the Char inside the String[index] and replace it with the null terminator.
    // We get the index of the newline character with strcspn().
    marke[strcspn(marke, "\n")] = '\0'; // Remove newline character

    printf("Enter Typ: ");
    fgets(typ, 16, stdin);
    typ[strcspn(typ, "\n")] = '\0'; // Remove newline character

    char baujahr_str[5];
    printf("Enter Baujahr: ");
    fgets(baujahr_str, sizeof(baujahr_str), stdin);
    *baujahr = atoi(baujahr_str);
}

void add_row(char *table, MYSQL *con)
{
    // Variables to store user input
    char marke[16];
    char typ[16];
    char query[256];
    int baujahr;

    // Get user input for the new row
    get_user_input(marke, typ, &baujahr);

    // Create the SQL query to insert the new row
    snprintf(query, sizeof(query), "INSERT INTO `%s`(`lfdNr`, `marke`, `typ`, `bauJahr`) VALUES(NULL, '%s', '%s', %d);", table, marke, typ, baujahr);

    // Execute the query
    if (mysql_query(con, query))
    {
        // If the query fails, print the error and exit
        finish_with_error(con);
    }

    // Print success message
    printf("Row added to the table '%s' successfully!\n", table);
}

void read_all_rows(char *table, MYSQL *con)
{
    MYSQL_RES *result;
    MYSQL_ROW row;
    char query[256];

    // Create the SQL query to select all rows
    snprintf(query, sizeof(query), "SELECT * FROM `%s`;", table);

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
}

void read_all_tables(MYSQL *con)
{
    MYSQL_RES *result;
    MYSQL_ROW row;

    // Create the SQL query to show all tables
    char query[] = "SHOW TABLES;";


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

    // Print the tables
    printf("Tables in the database:\n");
    while ((row = mysql_fetch_row(result)))
    {
        printf("%s\n", row[0]);
    }

    // Free the result
    mysql_free_result(result);
}

void login(login_info **login_info)
{
    char username[256] = {'\0'};
    char password[256] = {'\0'};

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove newline character

    // Lazy Dev Login; Sercurity risk!
    // This will skip the mannual login.
    if(strcmp(username, "aldi") == 0)
    {
        printf("Logged in as Aldi\n");
        // will use the default login, saved in the defines.
        (*login_info)->usesLogin = false;
        (*login_info)->isLoggedIn = true;
        return;
    }

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Remove newline character

    // Copy the input to the login_info structure
    strncpy((*login_info)->username, username, sizeof((*login_info)->username));
    strncpy((*login_info)->password, password, sizeof((*login_info)->password));

    // Set usesLogin to true
    (*login_info)->usesLogin = true;
    (*login_info)->isLoggedIn = true;
}

int main()
{
    int choice;
    char choice_str[3];

    // Login info struct is allocated on the heap
    // Why? Its cool, i guess. I just wanted to use dynamic memory allocation.
    // Using static memory allocation would be faster and more efficient.
    login_info *login_info = malloc(sizeof(login_info));

    // Initialize MySQL connection
    MYSQL *con = mysql_init(NULL);

    while(true)
    {
        printf("Choose an option:\n");
        printf("1. Log Into Database\n");

        // If the user is logged in, show additional options
        if(login_info->isLoggedIn)
        {
            printf("2. Add a row\n");
            printf("3. Read all rows\n");
            printf("4. Read all tables\n");
        }
        printf("9. Exit\n");
        printf("Enter your choice: ");

        fgets(choice_str, sizeof(choice_str), stdin);
        choice = atoi(choice_str);

        switch (choice)
        {
        case 1:
            login(&login_info);
            // Connect to the database
            dbContact(&con, &login_info);
            break;
        case 2:
            if(login_info->isLoggedIn)
                add_row(TABLE, con);
            break;
        case 3:
            if(login_info->isLoggedIn)
                read_all_rows(TABLE, con);
            break;
        case 4:
            if(login_info->isLoggedIn)
                read_all_tables(con);
            break;
        case 9:
            printf("Closing Client\n");
            endProgram(con, login_info);
        default:
            printf("Invalid choice!\n");
            break;
        }
    }

    // Free the login_info struct and close the MySQL connection
    free(login_info);
    mysql_close(con);
    return 0;
}