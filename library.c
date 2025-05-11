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
Book *loadLibrary();
void saveLibrary(Book *library);
void seedLibrary();
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
    while (command != 5)
    {
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
            add_book(&library, title, author, genre, isbn, date);
            // This command asks for what book they want to search and puts the information into search_book
        }
        else if (command == 2)
        {
            // This asks for what they want to look for such as a title or an author
            printf("what is the criteria for the search?");
            scanf(" %9[^\n]", criteria);
            // This asks for the specific name of the criteria
            printf("what is the query for the search?");
            scanf(" %99[^\n]", query);
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
            // This command asks for the isbn and checks out the book by accessing the check_out_book function
        }
        else if (command == 3)
        {
            printf("What is the isbn of the book you want to check out?\n");
            scanf(" %19[^\n]", isbn);
            check_out_book(&library, isbn);
            // This asks for the isbn and returns the book using the return_book function
        }
        else if (command == 4)
        {
            printf("What is the isbn of the book you want to return?\n");
            scanf(" %19[^\n]", isbn);
            return_book(&library, isbn);
            // This is the quit command
        }
        else if (command == 5)
        {
            break;
            // This is incase the user inputs something other than an int that is 1-5
        }
        else
        {
            printf("Error: command not understood\n");
        }
    }
    saveLibrary(library);
    return 0;
}

// This function adds a book to the end of a list
void add_book(Book **library, const char *title, const char *author, const char *genre, const char *isbn, const char *date)
{
    // Implement adding a book to the library
    Book *newBook = malloc(sizeof(Book));
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
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newBook;
}
Book *search_book(const Book *library, const char *query, const char *criteria)
{
    // Loop through the linked list
    while (library != NULL)
    {
        if (strcmp(criteria, "title") == 0)
        {
            if (strcmp(library->title, query) == 0)
            {
                return (Book *)library;
            }
        }
        else if (strcmp(criteria, "author") == 0)
        {
            if (strcmp(library->isbn, query) == 0)
            {
                return (Book *)library;
            }
        }
        else if (strcmp(criteria, "genre") == 0)
        {
            if (strcmp(library->isbn, query) == 0)
            {
                return (Book *)library;
            }
        }
        else if (strcmp(criteria, "isbn") == 0)
        {
            if (strcmp(library->isbn, query) == 0)
            {
                return (Book *)library;
            }
        }
        else if (strcmp(criteria, "date") == 0)
        {
            if (strcmp(library->isbn, query) == 0)
            {
                return (Book *)library;
            }
        }
        // try the next book
        library = library->next;
    }
    return NULL;
}
void check_out_book(Book **library, const char *isbn)
{
    // Implement checking out a book from the library
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
            library = NULL;
        }
    }
}
void return_book(Book **library, const char *isbn)
{
    // Implement returning a book to the library
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
            library = NULL;
        }
    }
}

Book *loadLibrary()
{
    FILE *books;
    Book head;
    head.next = NULL;
    Book *previous = &head;
    Book x;
    books = fopen("books.bin", "rb");
    if (books == NULL) {
        return NULL;
    }
    while (fread(&x, sizeof(Book), 1, books))
    {
        printf("title = %s author = %s\n", x.title, x.author);
        x.next = NULL;
        // Allocate space
        previous->next = malloc(sizeof *(previous->next));
        // Set the next node in the linked list
        *(previous->next) = x;
        // Advance to the next
        previous = previous->next;
    }
    fclose(books);
    return head.next;
}

void saveLibrary(Book *library)
{
    FILE *books;
    books = fopen("books.bin", "wb");
    while (library != NULL)
    {
        printf("title = %s author = %s\n", library->title, library->author);
        fwrite(library, sizeof(Book), 1, books);
        // save the next book
        library = library->next;
    }
}

void seedLibrary()
{
    FILE *books;
    books = fopen("books.bin", "a");
    Book hobbit = {"Hobbit", "JRR Tolkien", "fantasy", "9780547928227", "1937-09", true};
    Book dune = {"Dune", "Frank Herbert", "scifi", "9780441172719", "1965-08", true, &hobbit};
    fwrite(&hobbit, sizeof(Book), 1, books);
    fwrite(&dune, sizeof(Book), 1, books);
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