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
typedef struct {
char username[50];
char password[50];
char email[100];
char posts[MAX_POSTS][200];
int num_posts;
char followers[MAX_FOLLOWERS][50];
int num_followers;
} User;
// Function prototypes
void create_account(User *users, int *num_users);
void post_message(User *users, int num_users);
void follow_user(User *users, int num_users);
void generate_feed(User *users, int num_users);
/* 
void unfollow_user(User *users, int num_users);
void delete_account(User *users, int *num_users);
bool authenticate_user(User *users, int num_users);
void privacy_settings(User *users, int num_users);
*/
int main() {
// Test your functions here
return 0;
}
void create_account(User *users, int *num_users) {
// Implement creating a new user account
    printf("What is your username?\n");
    scanf(" %50[^\n]", users->username);
    printf("What is your password?\n");
    scanf(" %50[^\n]", users->password);
    printf("What is your email?\n");
    scanf(" %100[^\n]", users->email);
    users->num_posts=0;
    users->num_followers=0;
}
void post_message(User *users, int num_users) {
// Implement posting a message
    printf("What would you like to post(It can't be more than 200 charecters)?\n");
    scanf(" %200[^\n]", users->posts[users->num_posts][200]);
}
void follow_user(User *users, int num_users) {
// Implement following another user
    char username[50];
    printf("What username do you want to follow?");
    
}
void generate_feed(User *users, int num_users) {
// Implement generating a user's feed
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