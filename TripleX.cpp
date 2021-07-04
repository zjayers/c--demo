#include <iostream>
#include <numeric>
#include <vector>
#include <sstream>
#include <iterator>

void printIntroduction(int sum, int product) {
    std::cout
            << "You are codeA secret agent breaking into codeA secure server room." << std::endl
            << "You need to enter the correct code to continue..." << std::endl
            << "+ There are 3 numbers in the code." << std::endl
            << "+ The sum of the code sequences is: " << sum << std::endl
            << "+ The product of the code sequences is: " << product << std::endl;
}

void playGame(bool skipIntro) {
    const int codeA = 4;
    const int codeB = 3;
    const int codeC = 2;

    int guessA;
    int guessB;
    int guessC;

    std::vector<int> guesses;
    const char *delimiter = ",";

    const int sumOpStart = 0;
    const int multOpStart = 1;

    const std::vector<int> numbers = {codeA, codeB, codeC};

    const int sum = std::accumulate(numbers.begin(), numbers.end(), sumOpStart, std::plus<>());
    const int product = std::accumulate(numbers.begin(), numbers.end(), multOpStart, std::multiplies<>());

    if (!skipIntro) {
        printIntroduction(sum, product);
    }

    std::cout << "-- Please enter the first code number: ";

    std::cin >> guessA;

    std::cout
            << "+ You entered: " << guessA << std::endl
            << "-- Please enter the second code number: ";

    std::cin >> guessB;

    std::cout
            << "+ You entered: " << guessB << std::endl
            << "-- Please enter the third code number: ";

    std::cin >> guessC;

    guesses = {guessA, guessB, guessC};

    std::ostringstream out;

    if (!guesses.empty()) {
        std::copy(guesses.begin(), guesses.end() - 1, std::ostream_iterator<int>(out, delimiter));
        out << guesses.back();
    }

    std::string result = out.str();

    const int guessSum = std::accumulate(guesses.begin(), guesses.end(), sumOpStart, std::plus<>());
    const int guessProduct = std::accumulate(guesses.begin(), guesses.end(), multOpStart, std::multiplies<>());

    std::cout
            << "+ You entered: " << guessC << std::endl
            << "+ You entered code sequence: " << result << std::endl;

    if (guessSum == sum && guessProduct == product) {
        std::cout << "!!! You Win!";
    } else {
        std::cout << "XXX You Lose! Try again!" << std::endl << std::endl;
        playGame(true);
    }
}

int main() {
    playGame(false);
    return 0;
}

