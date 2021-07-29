#include <iostream>

bool PlayGame(int level)
{
    std::cout << "You are trying to guess the safes 3 number combination with a diffucilty raiting of " << level << std::endl;
    std::cout << "You need to enter the correct password to continue" << std::endl;

    const int firstNumber = rand() % (4 * level) + 1;
    const int secondNumber = rand() % (4 * level) + 1;
    const int thirdNumber = rand() % (4 * level) + 1;
    const int codeSum = firstNumber + secondNumber + thirdNumber;
    const int codeMulti = firstNumber * secondNumber * thirdNumber;

    std::cout << "The code adds up to - " << codeSum << std::endl;
    std::cout << "The code multiplies to - " << codeMulti << std::endl;

    int guessFirstNumber, guesssecondNumber, tuessThirdNumber;
    std::cout << "Enter the 3 numbers separated by spaces: ";
    std::cin >> guessFirstNumber >> guesssecondNumber >> tuessThirdNumber;
    std::cout << "you entered: " << guessFirstNumber << guesssecondNumber << tuessThirdNumber << std::endl;

    int GuessSum = guessFirstNumber + guesssecondNumber + tuessThirdNumber;
    int GuessMulti = guessFirstNumber * guesssecondNumber * tuessThirdNumber;

    if (codeSum == GuessSum && GuessMulti == codeMulti)
    {
        std::cout << "you beat " << level << "th level" << std::endl;
        return true;
    }
    std::cout << "Level failed" << std::endl;
    return false;
}

int main()
{
    const int maxDiffuculty = 7;
    int diffuculty = 1;
    while (diffuculty <= maxDiffuculty)
    {
        bool levelCompleted = PlayGame(diffuculty);
        std::cin.clear();
        std::cin.ignore();

        if (levelCompleted)
        {
            diffuculty++;
        }
    }

    return 0;
}