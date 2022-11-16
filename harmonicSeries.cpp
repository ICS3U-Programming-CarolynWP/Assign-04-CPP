// Copyright Carolyn
// Created by: Carolyn Webster Pless
// Created on: 22/11/14
// Gets the user input for a positive number
// Then uses a while loop to determine the sum of
// The harmonic series(1 / 2, 1 / 3, 1 / 4...) up to that
// Number.Then, it randomizes a number from 1 - 10 and uses a
// For loop to determine the sum of the harmonic series
// Up to that number.Finally, it determines the product of both
// Answers and displays it back to the user.

#include <iomanip>
#include <iostream>
#include <random>
#include <string>

int main() {
    // Variables
    std::string harmonicInputString;
    int harmonicInputInt;
    float harmonicInputFloat;
    int randomNumber;
    float harmonicSum = 0;
    float randomSum = 0;
    float product;
    float counter = 1;

    // Title
    std::cout << "Sum of the Harmonic Series\n";

    // generating the random number between 2 and 10
    std::random_device rseed;

    std::mt19937 rgen(rseed());

    std::uniform_int_distribution<int> idist(2, 10);

    // Random number
    randomNumber = idist(rgen);

        // User Input for the number
        std::cout << "Enter a positive integer:";
        std::cin >> harmonicInputString;

        // Try catch statement to check errors
        try {
            harmonicInputInt = std::stoi(harmonicInputString);
            float harmonicInputFloat = stof(harmonicInputString);

            // To make sure the user guess is not a decimal
            if (harmonicInputFloat != static_cast<int>(harmonicInputFloat)
            || harmonicInputFloat < 0) {
                std::cout << "Please enter a whole number!\n";
            } else {
                // IF statement to make sure the input is positive
                if (harmonicInputInt <= 0) {
                    std::cout << "Please enter a positive integer!\n";
                } else {
                    // WHILE loop to calculate the sum
                    while (counter <= harmonicInputInt) {
                        std::cout << "1/" << counter << "\n";
                        harmonicSum = harmonicSum + (1 / counter);
                        counter = counter + 1;
                    }
                    // Displaying the sum (std::fixed and
                    // std::setprecision found on stackoverflow)
                    std::cout << "The sum of the harmonic series up to "
                              << harmonicInputInt << " is "
                              << std::fixed << std::setprecision(2)
                              << harmonicSum << "\n";

                    // Setting the counter back to 1
                    counter = 1;
                    std::cout << "The random number is "
                    << randomNumber << "\n";

                    // Do While loop to calculate the sum of the
                    // Random number
                    do {
                        std::cout << "1/" << counter << "\n";
                        randomSum = randomSum + (1 / counter);
                        counter = counter + 1;
                    } while (counter <= randomNumber);
                    std::cout << "The random number's sum is " <<
                    std::fixed << std::setprecision(2) << randomSum << "\n";

                    // Calculating the product
                    product = harmonicSum * randomSum;

                    std::cout << "The product of both numbers are " <<
                    std::fixed << std::setprecision(2) << product << "\n";
                }
            }
        } catch (std::invalid_argument) {
            std::cout << "Please enter an integer!\n";
        }
}
