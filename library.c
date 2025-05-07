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
typedef struct Book {
    char title[100];
    char author[100];
    char genre[50];
    char isbn[20];
    char date[20];
    bool available;
    struct Book *next;
} Book;
// Function prototypes
void add_book(Book **library, const char title, const char author,
const char genre, const char isbn, const char date);
Book* search_book(const Book *library, const char *query, const char *criteria);
void check_out_book(Book **library, const char *isbn);
void return_book(Book **library, const char *isbn);
/*bool check_availability(const Book *library, const char *isbn);
void recommend_books(const Book *library, const char *isbn);
void manage_reservation_queue(Book **library, const char *isbn);
bool check_duplicate_book(const Book *library, const char *isbn);*/
int main() {
    // Test your functions here
    int command;
    char title[100],author[100],genre[50],isbn[20],date[20],criteria[10],query[100];
    Book hobbit = { "Hobbit", "JRR Tolkien", "fantasy", "9780547928227", "1937-09", true};
    Book dune = { "Dune", "Frank Herbert", "scifi", "9780441172719", "1965-08", true, &hobbit};
    Book* library = &dune;
    while(command != 5){
        printf("Which command do you want(type the number for what command you want)?\n");
        printf("Add book(1)\nSearch book(2)\nCheck out book(3)\nReturn book(4)\nQuit(5)\n");
        scanf("%i", &command);
        if(command == 1){
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
            add_book(&library, title[100], author[100], genre[50], isbn[20], date[20]);
        }else if(command == 2){
            printf("what is the criteria for the search?");
            scanf(" %9[^\n]", criteria);
            printf("what is the query for the search?");
            scanf(" %99[^\n]", query);
            const Book* result = search_book(&dune, query, criteria);
            if(result == NULL){
                printf("We do not have that book\n");
            }else{
                printf("%s\n", result->title);
                printf("%s\n", result->author);
                printf("%s\n", result->genre);
                printf("%s\n", result->isbn);
                printf("%s\n", result->date);
                printf("%d\n", result->available);
            }
        }else if(command == 3){
            printf("What is the isbn of the book you want to check out?\n");
            scanf(" %19[^\n]", isbn);
            check_out_book(&library, isbn);
        }else if(command == 4){
            printf("What is the isbn of the book you want to return?\n");
            scanf(" %19[^\n]", isbn);
            return_book(&library, isbn);
        }else{
            printf("Error: command not understood\n");
        }
    }
    return 0;
}
void add_book(Book **library, const char title, const char author, const char genre, const char isbn, const char date) {
    // Implement adding a book to the library
    Book *temp;
    //Alcates memory for the new book
    temp=(Book*)malloc(sizeof(Book));
    //Fills in the information for the new book
    *temp->title=title;
    *temp->author=author;
    *temp->genre=genre;
    *temp->isbn=isbn;
    *temp->date=date;
    temp->available=true;
    temp->next=NULL;
    Book* ptr=*library;
    //This puts the new book at the end of the list
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
}
Book* search_book(const Book *library, const char *query, const char *criteria) {
    // Loop through the linked list
    while (library != NULL) {
        if (strcmp(criteria, "title") == 0) {
            if (strcmp(library->title, query) == 0) {
                return (Book*)library;
            }
        } else if (strcmp(criteria, "author") == 0) {
            if (strcmp(library->isbn, query) == 0) {
                return (Book*)library;
            }
        }else if (strcmp(criteria, "genre") == 0) {
            if (strcmp(library->isbn, query) == 0) {
                return (Book*)library;
            }
        }else if (strcmp(criteria, "isbn") == 0) {
            if (strcmp(library->isbn, query) == 0) {
                return (Book*)library;
            }
        }else if (strcmp(criteria, "date") == 0) {
            if (strcmp(library->isbn, query) == 0) {
                return (Book*)library;
            }
        }
        // try the next book
        library = library->next;
    }
    return NULL;
}
void check_out_book(Book **library, const char *isbn) {
    // Implement checking out a book from the library
    while (library != NULL) {
        //Find the book that you are looking for
        if (strcmp((*library)->isbn, isbn) == 0) {
            //Change the availability
            (*library)->available = false;
            printf("Book checked out\n");
            break;
        }
        // try the next book
        if ((*library)->next) {
            library = &((*library)->next);
        } else {
            library = NULL;
        }
        
    }
}
void return_book(Book **library, const char *isbn) {
    // Implement returning a book to the library
    while (library != NULL) {
        //Find the book that you want to return
        if (strcmp((*library)->isbn, isbn) == 0) {
            //change the availablitity 
            (*library)->available = true;
            printf("Book returned\n");
            break;
        }
        // try the next book
        if ((*library)->next) {
            library = &((*library)->next);
        } else {
            library = NULL;
        }
    }
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