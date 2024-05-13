#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int numberToGuess = std::rand() % 100 + 1;

    int guess;
    do
    {
        std::cout << "Guess a number between 1 and 100: ";
        std::cin >> guess;

        if (guess < numberToGuess)
        {
            std::cout << "Too low! Try again." << std::endl;
        }
        else if (guess > numberToGuess)
        {
            std::cout << "Too high! Try again." << std::endl;
        }
    } while (guess != numberToGuess);

    std::cout << "Congratulations! You guessed the correct number: " << numberToGuess << std::endl;
    return 0;
}