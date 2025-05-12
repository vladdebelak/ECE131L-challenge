/*
Welcome to the Social Media Platform template for your programming challenge!
This template is designed to help you implement various functions required to
build a basic social media platform.

Below is a brief guide on how you can use this template to complete the challenge:

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
the functions from the `main` function or by writing additional test cases.
Ensure that your functions produce the expected outputs and handle edge cases
appropriately.
IF NOT, YOU WILL NOT RECEIVE ANY CREDIT!

4. **Error Handling and Input Validation**: Pay close attention to error handling
and input validation to ensure a smooth user experience.
Handle invalid inputs and edge cases gracefully to prevent program crashes.

5. **Time Complexity Analysis**: Analyze the time complexity of each function to
ensure efficient performance.
Consider factors such as the size of user data and the efficiency of algorithms
used.

6. **Documentation**: Add comments throughout your code to explain your
implementation logic, especially for complex algorithms or data structures.

7. **Optimization**: While implementing the functions, consider ways to optimize
your code for performance and efficiency.
This includes minimizing time complexity and utilizing appropriate data structures
and algorithms.

8. **Additional Tasks**: If you're up for an extra challenge, you should also
implement the additional tasks mentioned in the challenge description.

9. **Submission**: Once you've completed all the required functions and tasks, you
should submit your code for evaluation based on the provided evaluation criteria.
Feel free to modify the template as needed to suit your implementation style and
preferences. Good luck, and happy coding!

Dr. Petro M. Tshakwanda
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_USERS 100
#define MAX_POSTS 1000
#define MAX_FOLLOWERS 100
typedef struct
{
    char username[50];
    char password[50];
    char email[100];
    char posts[MAX_POSTS][200];
    int num_posts;
    char followers[MAX_FOLLOWERS][50];
    int num_followers;
    // I made this structure a linked list
    struct User *next;
} User;
// Function prototypes
void create_account(User **platform);
void post_message(User **platform);
void follow_user(User **platform);
void generate_feed(User *platform);
// I added these functions
// This function loads whatever is in the file into the linked list
User *loadPlatform(int *num_users);
// This function saves whatever is in the linked list into the file
void savePlatform(User *platform);
/*
void unfollow_user(User *users, int num_users);
void delete_account(User *users, int *num_users);
bool authenticate_user(User *users, int num_users);
void privacy_settings(User *users, int num_users);
*/
int main()
{
    // this is just declaring the ints
    int num_users = 0, command = 0;
    // This puts whatever is in the file into the platform User struct by using the load platform function
    User *platform = loadPlatform(&num_users);
    // Test your functions here
    // This loop is just for the command and what they want
    // The time complexity is O(n) because it is just one while loop
    while (command != 5)
    {
        // This just asks for what command the user wants
        printf("Create Account(1)\nPost Message(2)\nFollow User(3)\nGenerate Feed(4)\nSave and Quit(5)\n");
        printf("What command would you like?");
        scanf("%i", &command);
        // This command is is to add a new user
        if (command == 1)
        {
            // This is just to make sure there anr't too many users
            if (num_users < MAX_USERS)
            {
                // Increase the amount of users and then create a new user with the function
                num_users++;
                create_account(&platform);
            }
            else
            {
                // Just some error handling 
                printf("Error: There is no more room for more users\n");
            }
        }
        // For command 2 is posting a message
        else if (command == 2)
        {
            // Access the function
            post_message(&platform);
        }
        // Command command 3 is to follow a user
        else if (command == 3)
        {
            // This is the function to follow the user
            follow_user(&platform);
        }
        // This command 4 is to generate a feed
        else if (command == 4)
        {
            //This function is to generate the feend
            generate_feed(&platform);
        }
        // This is if the user want to quit
        else if (command == 5)
        {
            break;
        }
        // In case they input something else
        else
        {
            printf("Error: command not understood\n");
        }
    }
    // This is to save it into the file
    savePlatform(platform);
    return 0;
}
// This function creates an account using the double pointer user struct platform
// The time complexity of this function is O(n) because there is a loop
// This function is void because we just add the informating at the end of the linked list and it is a pointer
void create_account(User **platform)
{
    // Implement creating a new user account
    // This allocates memory to the new user struct
    User *newUser = malloc(sizeof(User));
    // declaring chars
    char username[50], password[50], email[100];
    // asking for the information and putting it into the linked list
    printf("What is your username?\n");
    scanf(" %49[^\n]", username);
    printf("What is your password?\n");
    scanf(" %49[^\n]", password);
    printf("What is your email?\n");
    scanf(" %99[^\n]", email);
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    strcpy(newUser->email, email);
    newUser->num_followers = 0;
    newUser->num_posts = 0;
    newUser->next = NULL;
    // If the platform is empty, this is our platform
    if (*platform == NULL) {
        *platform = newUser;
        return;
    }
    // // Store the head reference in a temporary variable 
    User *last = *platform;
    // Traverse till the last node
    while (last->next != NULL)
    {
        // fo to the next one
        last = last->next;
    }
    //Put it at the end of the linked list
    last->next = newUser;
}
// This function post a message
// This functions time complexity is O(n) because it has one while loop
// This function is void because we just put it into the matrix in the struct and we need the double pointer platform struct
void post_message(User **platform)
{
    // Implement posting a message;
    // char username
    char username[50];
    // ask for the useranem
    printf("What is your username\n");
    scanf(" %49[^\n]", username);
    // This loop just finds the user with the username 
    while (platform != NULL)
    {
        // Find the username that you are looking for
        if (strcmp((*platform)->username, username) == 0)
        {
            // If we found it, break out of the loop
            break;
        }
        // try the next user
        if ((*platform)->next)
        {
            platform = &((*platform))->next;
        }
        else
        {
            // This is if the username doesn't exist
            printf("Error: We did not find anyone with that username\n");
            return;
        }
    }
    // This if statement checks to make sure there arn't too many posts
    if ((*platform)->num_posts < MAX_POSTS)
    {
        // Asks for what they want to post
        printf("What would you like to post(It can't be more than 200 charecters)?\n");
        scanf(" %200[^\n]", (*platform)->posts[(*platform)->num_posts]);
        // increase the number of posts they have posted
        (*platform)->num_posts++;
    }
    else
    {
        // This is incase they have already posted their limit
        printf("Error: You have already reached your maximum number of posts\n");
        return;
    }
}
// This function follows a user using the double pointer User platform struct
// The time complexity of this function is O(n) because there is just one while loop
// This function is void because we just follow a user and we don't have to use anything from this function, escpecially since it is a pointer
void follow_user(User **platform)
{
    // Implement following another user
    // Declare the char
    char username[50];
    // Ask for the username
    printf("What is your username\n");
    scanf(" %49[^\n]", username);
    //  This loop searches for the username 
    while (platform != NULL)
    {
        // Find the username that you are looking for
        if (strcmp((*platform)->username, username) == 0)
        {
            // Break when we find it
            break;
        }
        // try the next user
        if ((*platform)->next)
        {
            platform = &((*platform))->next;
        }
        else
        {
            // In case the username doesn't exist
            printf("Error: We did not find anyone with that username\n");
            return;
        }
    }
    //This makes sure there anr't too many followers
    if ((*platform)->num_followers < MAX_FOLLOWERS)
    {
        // Ask for who you want to follow and put it into the followers matrix
        printf("What username do you want to follow?");
        scanf(" %49[^\n]", (*platform)->username[(*platform)->num_followers]);
        // Increase the number of followers you have
        (*platform)->num_followers++;
    }
    // In case they have reached the maximum
    else
    {
        printf("Error: You have reached the maximum number of followers\n");
    }
}
// This function generates the feed using a pointer User users struct
// The time complexity is O(n^s) because the nested loop dominates and is the biggest factor
// This function is void because we just print out the posts of the followers and don't actually change anything
void generate_feed(User *users)
{
    // Implement generating a user's feed
    // Declare the char and two ints
    char username[50];
    int i, j;
    // Ask for the username
    printf("What is your username\n");
    scanf(" %49[^\n]", username);
    // As long as the linked list isn't empty..≥
    while (users != NULL)
    {
        // Find the username that you are looking for
        if (strcmp(users->username, username) == 0)
        {
            // Break when you have found it
            break;
        }
        // try the next user
        if (users->next)
        {
            users = &(users)->next;
        }
        else
        {
            // In case the username dosn't exist
            printf("Error: We did not find anyone with that username\n");
            return;
        }
    }
    // In case the user doesn;t have any followers
    if (users->followers == NULL)
    {
        printf("Error: You do not have any followers\n");
    }
    else
    {
        // This loop will run from 0 to the number of followers
        for (i = 0; i < users->num_followers; i++)
        {
            // Set the char temporaraly to to the i'th follower
            char follower = *users->followers[i];
            // As long as the linked list isn't empty...
            while (users != NULL)
            {
                // Find the username that you are looking for
                if (strcmp(users->username, &follower) == 0)
                {
                    // Print the follower
                    printf("%s:\n", follower);
                    // This loop goes from 0 to the number of posts the follower has
                    for (j = 0; j < users->num_posts; j++)
                    {
                        // Print the j'th post
                        printf("%s\n", users->posts[j]);
                    }
                }
                // try the next user
                if (users->next)
                {
                    users = &(users)->next;
                }
            }
        }
    }
}
// This loads the information of a file into a linked list in the begining of main
// This just asks for the pointer num_users
// We return the linked list where we loaded the information from the file
// The time complexity is O(n) because there is one while loop
User *loadPlatform(int *num_users)
{
    // Open the file along with the structs we need
    FILE *platform;
    User head;
    head.next = NULL;
    User *previous = &head;
    User x;
    // Open the file
    platform = fopen("users.bin", "rb");
    // If the file is empty, return NULL
    if (platform == NULL) {
        return NULL;
    }
    // Read from the file once with size of User
    while (fread(&x, sizeof(User), 1, platform))
    {
        // Print some information
        printf("username = %s email = %s\n", x.username, x.email);
        x.next = NULL;
        // Allocate space
        previous->next = malloc(sizeof previous->next);
        // Set the next node in the linked list
        previous->next = &x;
        // Advance to the next
        previous = previous->next;
        num_users++;
    }
    // Close file and return the linked list
    fclose(platform);
    return head.next;
}
// This file saves the information from the linked list into the file at the end of main
// The time complexity is O(n) because there is one loop
// The functions needs the linked list and it is void since it is the last thing we do and it just puts info into the file
void savePlatform(User *users)
{
    // Declare the file and open it
    FILE *platform;
    // We want wb because it is a binary file and we want to get rid of whatever is in there since it will be outdated info
    platform = fopen("users.bin", "wb");
    // As long as the linked list isn't empty...
    while (users != NULL)
    {
        // Write the linked list into the file
        fwrite(users, sizeof(User), 1, platform);
        // save the next book
        users = users->next;
    }
}
/*
These are the optional functions
void unfollow_user(User *users, int num_users) {
// Implement unfollowing a user
}
void delete_account(User *users, int *num_users) {
// Implement deleting a user account
}
bool authenticate_user(User *users, int num_users) {
// Implement user authentication
}
void privacy_settings(User *users, int num_users) {
// Implement privacy settings for user accounts
}
*/