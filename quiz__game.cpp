#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// ANSI escape codes for colors
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

// Structure to hold a question, options, and the correct answer
struct Question {
    string questionText;
    vector<string> options;
    char correctAnswer;
};

// Function to display a question and get the user's answer
char askQuestion(Question q, int questionNumber, int totalQuestions) {
    cout << CYAN << "\nQuestion " << questionNumber << " of " << totalQuestions << ": " << q.questionText << RESET << endl;
    for (size_t i = 0; i < q.options.size(); i++) {
        cout << YELLOW << char('A' + i) << ". " << q.options[i] << RESET << endl;
    }
    
    char userAnswer;
    cout << "Enter your answer (A/B/C/D): ";
    cin >> userAnswer;
    return toupper(userAnswer);
}

int main() {
    srand(time(0)); // Seed for randomization

    cout << "\n";
    cout << "=========================================" << endl;
    cout << "          WELCOME TO THE RIDDLE QUIZ!" << endl;
    cout << "=========================================" << endl;
    cout << "Can you solve these tricky riddles? Let's see!\n" << endl;

    vector<Question> quiz = {
        {"What has to be broken before you can use it?", {"Glass", "Egg", "Lock", "Seal"}, 'B'},
        {"I speak without a mouth and hear without ears. What am I?", {"Echo", "Shadow", "Wind", "Ghost"}, 'A'},
        {"The more of me you take, the more you leave behind. What am I?", {"Footsteps", "Memories", "Breath", "Time"}, 'A'},
        {"What comes once in a minute, twice in a moment, but never in a thousand years?", {"Letter M", "Sound", "Blink", "Time"}, 'A'},
        {"I have hands but cannot clap. What am I?", {"Clock", "Statue", "Robot", "Mannequin"}, 'A'}
    };

    int score = 0;
    int totalQuestions = quiz.size();

    for (int i = 0; i < totalQuestions; i++) {
        char answer = askQuestion(quiz[i], i + 1, totalQuestions);
        if (answer == quiz[i].correctAnswer) {
            cout << GREEN << "Correct! 🎉" << RESET << endl;
            score++;
        } else {
            cout << RED << "Wrong! The correct answer was " << quiz[i].correctAnswer << "." << RESET << endl;
        }
        cout << "------------------------" << endl;
    }
    
    // Display final score with a remark
    cout << "\n=========================================" << endl;
    cout << "           QUIZ COMPLETED!" << endl;
    cout << "=========================================" << endl;
    cout << "You scored " << score << " out of " << totalQuestions << "!" << endl;

    if (score == totalQuestions) {
        cout << GREEN << "Amazing! You're a riddle master! 🏆" << RESET << endl;
    } else if (score > totalQuestions / 2) {
        cout << YELLOW << "Great job! You're pretty good at this! 👍" << RESET << endl;
    } else {
        cout << RED << "Better luck next time! Keep practicing! 💪" << RESET << endl;
    }
    return 0;
}