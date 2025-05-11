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
    struct User *next;
} User;
// Function prototypes
void create_account(User **platform);
void post_message(User **platform);
void follow_user(User **platform);
void generate_feed(User *platform);
User *loadPlatform(int *num_users);
void savePlatform(User *platform);
/*
void unfollow_user(User *users, int num_users);
void delete_account(User *users, int *num_users);
bool authenticate_user(User *users, int num_users);
void privacy_settings(User *users, int num_users);
*/
int main()
{
    int num_users = 0, command = 0;
    User *platform = loadPlatform(&num_users);
    
    char users[MAX_USERS];
    // Test your functions here
    while (command != 5)
    {
        printf("Create Account(1)\nPost Message(2)\nFollow User(3)\nGenerate Feed(4)\nSave and Quit(5)\n");
        printf("What command would you like?");
        scanf("%i", &command);
        if (command == 1)
        {
            if (num_users < MAX_USERS)
            {
                num_users++;
                create_account(&platform);
            }
            else
            {
                printf("Error: There is no more room for more users\n");
            }
        }
        else if (command == 2)
        {
            post_message(&platform);
        }
        else if (command == 3)
        {
            follow_user(&platform);
        }
        else if (command == 4)
        {
            // generate_feed(&platform,num_users);
        }
        else if (command == 5)
        {
            break;
        }
        else
        {
            printf("Error: command not understood\n");
        }
    }
    savePlatform(platform);
    return 0;
}
void create_account(User **platform)
{
    // Implement creating a new user account
    User *newUser = malloc(sizeof(User));
    char username[50], password[50], email[100];
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
        last = last->next;
    }
    last->next = newUser;
}
void post_message(User **platform)
{
    // Implement posting a message;
    char username[50];
    printf("What is your username\n");
    scanf(" %49[^\n]", username);
    while (platform != NULL)
    {
        // Find the username that you are looking for
        if (strcmp((*platform)->username, username) == 0)
        {
            break;
        }
        // try the next user
        if ((*platform)->next)
        {
            platform = &((*platform))->next;
        }
        else
        {
            printf("Error: We did not find anyone with that username\n");
            return;
        }
        if ((*platform)->num_posts < MAX_POSTS)
        {
            printf("What would you like to post(It can't be more than 200 charecters)?\n");
            scanf(" %200[^\n]", (*platform)->posts[(*platform)->num_posts]);
            (*platform)->num_posts++;
        }
        else
        {
            printf("Error: You have already reached your maximum number of posts\n");
            return;
        }
    }
}
void follow_user(User **platform)
{
    // Implement following another user
    char username[50];
    printf("What is your username\n");
    scanf(" %49[^\n]", username);
    while (platform != NULL)
    {
        // Find the username that you are looking for
        if (strcmp((*platform)->username, username) == 0)
        {
            break;
        }
        // try the next user
        if ((*platform)->next)
        {
            platform = &((*platform))->next;
        }
        else
        {
            printf("Error: We did not find anyone with that username\n");
            return;
        }
    }
    if ((*platform)->num_followers < MAX_FOLLOWERS)
    {
        printf("What username do you want to follow?");
        scanf(" %49[^\n]", (*platform)->username[(*platform)->num_followers]);
        (*platform)->num_followers++;
    }
    else
    {
        printf("Error: You have reached the maximum number of followers\n");
    }
}
void generate_feed(User *users)
{
    // Implement generating a user's feed
    char username[50];
    int i, j;
    printf("What is your username\n");
    scanf(" %49[^\n]", username);
    while (users != NULL)
    {
        // Find the username that you are looking for
        if (strcmp(users->username, username) == 0)
        {
            break;
        }
        // try the next user
        if (users->next)
        {
            users = &(users)->next;
        }
        else
        {
            printf("Error: We did not find anyone with that username\n");
            return;
        }
    }
    if (users->followers == NULL)
    {
        printf("Error: You do not have any followers\n");
    }
    else
    {
        for (i = 0; i < users->num_followers; i++)
        {
            char follower = *users->followers[i];
            while (users != NULL)
            {
                // Find the username that you are looking for
                if (strcmp(users->username, &follower) == 0)
                {
                    printf("%s:\n", follower);
                    for (j = 0; j < users->num_posts; j++)
                    {
                        printf("%s\n", users->posts[j]);
                    }
                    break;
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
User *loadPlatform(int *num_users)
{
    FILE *platform;
    User head;
    head.next = NULL;
    User *previous = &head;
    User x;
    platform = fopen("users.bin", "rb");
    // If the file is empty, return NULL
    if (platform == NULL) {
        return NULL;
    }
    while (fread(&x, sizeof(User), 1, platform))
    {
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
    fclose(platform);
    return head.next;
}
void savePlatform(User *users)
{
    FILE *platform;
    platform = fopen("users.bin", "wb");
    while (users != NULL)
    {
        fwrite(users, sizeof(User), 1, platform);
        // save the next book
        users = users->next;
    }
}
/*
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