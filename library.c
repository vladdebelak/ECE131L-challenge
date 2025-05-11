/*
Welcome to the Library Management System template for your programming challenge!
This template is designed to help you implement various functions required to
build a functional library management system. Below is a brief guide on how you
can use this template to complete the challenge:

1. **Understanding the Structure**: Take a moment to review the structure of the
provided template.
You'll notice that it includes function prototypes for each required function, as
well as a `main` function where you can test your implementations.

2. **Function Implementations**: Your task is to complete the implementation of
each function according to the specifications provided in the challenge
description.
Each function has a comment indicating where you should implement the corresponding
functionality.

3. **Testing Your Code**: Once you've completed the implementations, you should
test your code by calling
the functions from the `main` function or by writing additional test cases. Ensure
that your functions produce the expected outputs and handle edge cases
appropriately.

IF NOT, YOU WILL NOT RECEIVE ANY CREDIT!

4. **Time Complexity Analysis**: Don't forget to analyze the time complexity of
each function.
You can implement the `analyze_time_complexity` function to provide a brief
analysis of the time complexity of your implementations.

5. **Documentation**: You are required to add comments throughout your code to
explain your implementation logic,
especially for complex algorithms or data structures.

6. **Optimization**: While implementing the functions, consider ways to optimize
your code for performance and efficiency.
This includes minimizing time complexity and utilizing appropriate data structures
and algorithms.

7. **Additional Tasks**: If you're up for an extra challenge, you should also
implement the additional tasks mentioned in the challenge description.

8. **Submission**: Once you've completed all the required functions and tasks, you
should submit your code for evaluation based on the provided evaluation criteria.
Feel free to modify the template as needed to suit your implementation style and
preferences. Good luck, and happy coding!

Dr. Petro Mushidi Tshakwanda
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Define structure for Book
typedef struct Book
{
    char title[100];
    char author[100];
    char genre[50];
    char isbn[20];
    char date[20];
    bool available;
    struct Book *next;
} Book;
// Function prototypes
void add_book(Book **library, const char *title, const char *author,
              const char *genre, const char *isbn, const char *date);
Book *search_book(const Book *library, const char *query, const char *criteria);
void check_out_book(Book **library, const char *isbn);
void return_book(Book **library, const char *isbn);
// I added these functions
// This one loads whatever is in the file into a linked listv at the beginning of the code
Book *loadLibrary();
// This is to put whatever is in the linked list into the file at the end of the code
void saveLibrary(Book *library);
// This is incase your library is empty and you want to add some books I have allready saved
void seedLibrary();
// These are the optional functions
/*bool check_availability(const Book *library, const char *isbn);
void recommend_books(const Book *library, const char *isbn);
void manage_reservation_queue(Book **library, const char *isbn);
bool check_duplicate_book(const Book *library, const char *isbn);*/
int main()
{
    // Declare the ints and chars
    int command;
    char title[100], author[100], genre[50], isbn[20], date[20], criteria[10], query[100];

    // If needed, seed library
    // seedLibrary();

    // Load library
    Book *library = loadLibrary();

    // This loop just asks what commands they want
    // The time complexity is O(n) because it executes as a loop
    while (command != 5)
    {
        // This just asks for what commands are wanted
        printf("Which command do you want(type the number for what command you want)?\n");
        printf("Add book(1)\nSearch book(2)\nCheck out book(3)\nReturn book(4)\nSave and quit(5)\n");
        scanf("%i", &command);
        // This command asks for all the books information and then puts it into the add_book function
        if (command == 1)
        {
            // All the scanf functions have one less because otherwise there is an error
            printf("What is the tile of the book?\n");
            scanf(" %99[^\n]", title);
            printf("What is the author of the book?\n");
            scanf(" %99[^\n]", author);
            printf("What is the genre of the book?\n");
            scanf(" %49[^\n]", genre);
            printf("What is the isbn of the book?\n");
            scanf(" %19[^\n]", isbn);
            printf("What is the date of publication for the book?\n");
            scanf(" %19[^\n]", date);
            // This accesses the add book function
            add_book(&library, title, author, genre, isbn, date);
        }
        // This command asks for what book they want to search and puts the information into search_book
        else if (command == 2)
        {
            // This asks for what they want to look for such as a title or an author
            printf("what is the criteria for the search?");
            scanf(" %9[^\n]", criteria);
            // This asks for the specific name of the criteria
            printf("what is the query for the search?");
            scanf(" %99[^\n]", query);
            // This is just accessing the function and putting it into result
            const Book *result = search_book(library, query, criteria);
            // This is just to let the user know if there is no book that they looked for
            if (result == NULL)
            {
                printf("We do not have that book\n");
            }
            else
            {
                // This just prints the results if it is not NULL
                printf("%s\n", result->title);
                printf("%s\n", result->author);
                printf("%s\n", result->genre);
                printf("%s\n", result->isbn);
                printf("%s\n", result->date);
                printf("%d\n", result->available);
            }
        }
        // This command asks for the isbn and checks out the book by accessing the check_out_book function
        else if (command == 3)
        {
            // This asks for the isbn
            printf("What is the isbn of the book you want to check out?\n");
            scanf(" %19[^\n]", isbn);
            // accessing the check out book function
            check_out_book(&library, isbn);
        }
        // This asks for the isbn and returns the book using the return_book function
        else if (command == 4)
        {
            // This asks for the isbn
            printf("What is the isbn of the book you want to return?\n");
            scanf(" %19[^\n]", isbn);
            // This accesses the return book function 
            return_book(&library, isbn);
            // This is the quit command
        }
        // This is if the user want to quit
        else if (command == 5)
        {
            break;
        }
        // This is incase the user inputs something other than an int that is 1-5
        else
        {
            printf("Error: command not understood\n");
        }
    }
    // This is to access the save library function
    saveLibrary(library);
    return 0;
}

// This function adds a book to the end of a list
// This function need a struct, library, and also the information of the book which are title, author, genre, isbn and date
// This function is void because we just add a new book to the end 
void add_book(Book **library, const char *title, const char *author, const char *genre, const char *isbn, const char *date)
{
    // Implement adding a book to the library
    // Setting a side a some memory
    Book *newBook = malloc(sizeof(Book));
    // coping the information 
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->genre, genre);
    strcpy(newBook->isbn, isbn);
    strcpy(newBook->date, date);

    // If the library is empty, this is our library
    if (*library == NULL) {
        *library = newBook;
        return;
    }
    // Store the head reference in a temporary variable 
    Book *last = *library;
    // Traverse till the last node
    // The time complexity O(n) because it is just a normal loop that executes iterativly 
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newBook;
}
// This function searches for a book
// This function asks for the struct library and a query and criteria 
// This function returns the a Book struct because we need the struct to print the information 
Book *search_book(const Book *library, const char *query, const char *criteria)
{
    // Loop through the linked list as long as the library in not empty 
    // The time complexity is O(n) because even though there are many if statements, its still just one while statement
    while (library != NULL)
    {
        // This is for the case if the critiria is title
        if (strcmp(criteria, "title") == 0)
        {
            // If the book that we currently are on has the title the same as the query, we return the book
            if (strcmp(library->title, query) == 0)
            {
                return (Book *)library;
            }
        }
        // This is for the case if the critiria is author
        else if (strcmp(criteria, "author") == 0)
        {
            // If the book that we currently are on has the author the same as the query, we return the book
            if (strcmp(library->author, query) == 0)
            {
                return (Book *)library;
            }
        }
        // This is for the case if the critiria is genre
        else if (strcmp(criteria, "genre") == 0)
        {
            // If the book that we currently are on has the genre the same as the query, we return the book
            if (strcmp(library->genre, query) == 0)
            {
                return (Book *)library;
            }
        }
        // This is for the case if the critiria is isbn
        else if (strcmp(criteria, "isbn") == 0)
        {
            // If the book that we currently are on has the isbn the same as the query, we return the book
            if (strcmp(library->isbn, query) == 0)
            {
                return (Book *)library;
            }
        }
        // This is for the case if the critiria is date
        else if (strcmp(criteria, "date") == 0)
        {
            // If the book that we currently are on has the date the same as the query, we return the book
            if (strcmp(library->date, query) == 0)
            {
                return (Book *)library;
            }
        }
        // try the next book
        library = library->next;
    }
    // If we didn't find the book, we return NULL 
    return NULL;
}
// This function checks out a book
// This function asks for a struct and the isbn
// This function is void because we just change the availability and the struct is a double pointer
void check_out_book(Book **library, const char *isbn)
{
    // Implement checking out a book from the library
    // The time complecity is O(n) because it is just one while loop that iterates
    // This loop runs whenever the library isn't empty 
    while (library != NULL)
    {
        // Find the book that you are looking for
        if (strcmp((*library)->isbn, isbn) == 0)
        {
            // Change the availability
            (*library)->available = false;
            printf("Book checked out\n");
            break;
        }
        // try the next book
        if ((*library)->next)
        {
            library = &((*library)->next);
        }
        else
        {
            // This will end the loop if we are at the end of the list 
            library = NULL;
        }
    }
}
// This function return a book
// This function needs a Book struct, library, and also the isbn
// This function is void because we just need to change the availability 
void return_book(Book **library, const char *isbn)
{
    // Implement returning a book to the library
    // The time complexity is O(n) because it is just one while loop that iterates
    // This while loop runs whenever the library isnt empty 
    while (library != NULL)
    {
        // Find the book that you want to return
        if (strcmp((*library)->isbn, isbn) == 0)
        {
            // change the availablitity
            (*library)->available = true;
            printf("Book returned\n");
            break;
        }
        // try the next book
        if ((*library)->next)
        {
            library = &((*library)->next);
        }
        else
        {
            // This will end the loop if we are at the end of the list
            library = NULL;
        }
    }
}
// This function will take whatever is in the file and put it into a linked list
// This function is called on in the beginning of the main
// This returns a struct because we need to use the linked list
Book *loadLibrary()
{
    // This just declares the file and all the structs we want to use
    FILE *books;
    Book head;
    head.next = NULL;
    Book *previous = &head;
    Book x;
    // This opens the file for binary reading 
    books = fopen("books.bin", "rb");
    // If the file is empty, return NULL
    if (books == NULL) {
        return NULL;
    }
    // This loop will read the file in sizes of the book struct
    // The time complexity is O(n) because we just iterate through the loop once
    while (fread(&x, sizeof(Book), 1, books))
    {
        // This prints out the title and the author
        printf("title = %s author = %s\n", x.title, x.author);
        x.next = NULL;
        // Allocate space
        previous->next = malloc(sizeof *(previous->next));
        // Set the next node in the linked list
        *(previous->next) = x;
        // Advance to the next
        previous = previous->next;
    }
    // close the file
    fclose(books);
    // return the struct for use
    return head.next;
}
// This function puts the linked list, we ask for it, the book struct library, into the file
// This is void because this is the last thing we do in main and we don't need anything anymore
void saveLibrary(Book *library)
{
    // Declare the file and open it into writing so that it will get rid of anything that might be in the file
    FILE *books;
    books = fopen("books.bin", "wb");
    // This function will write the linked list into the file as long as the library linked list isn't empty 
    // The time complexity of this loop is O(n)
    while (library != NULL)
    {
        // print the title and author that there is
        printf("title = %s author = %s\n", library->title, library->author);
        // write into the file, the library of each link
        fwrite(library, sizeof(Book), 1, books);
        // save the next book
        library = library->next;
    }
    // close the file
    fclose(books);
}
// This function is O(1) since there is no loop
// This function seeds the library is whoever is running this want some books to start with
// This is void because we are just adding books into the file
void seedLibrary()
{
    // Create a file and open it
    FILE *books;
    books = fopen("books.bin", "a");
    // These are the books you can seed
    Book hobbit = {"Hobbit", "JRR Tolkien", "fantasy", "9780547928227", "1937-09", true};
    Book dune = {"Dune", "Frank Herbert", "scifi", "9780441172719", "1965-08", true, &hobbit};
    // write the books into the file
    fwrite(&hobbit, sizeof(Book), 1, books);
    fwrite(&dune, sizeof(Book), 1, books);
    // close the file
    fclose(books);
}
/*These next functions are optional
bool check_availability(const Book *library, const char *isbn) {
// Implement checking the availability of a specific book
}
void recommend_books(const Book *library, const char *isbn) {
// Implement recommending similar books
printf("Recommendations based on book with ISBN %s:\n", isbn);
// Implementation of recommendation logic
}
void manage_reservation_queue(Book **library, const char *isbn) {
// Implement managing the reservation queue
printf("Managing reservation queue for book with ISBN %s\n", isbn);
// Implementation of reservation queue management
}
bool check_duplicate_book(const Book *library, const char *isbn) {
// Implement checking for duplicates before adding a new book
}*/