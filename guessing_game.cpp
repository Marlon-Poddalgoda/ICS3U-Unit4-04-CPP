// Copyright (c) 2020 Marlon Poddalgoda, All rights reserved
//
// Created by Marlon Poddalgoda
// Created on December 2020
// This program is a guessing game

#include <iostream>
#include <string>
#include <random>

int main() {
    // this function compares an integer to a random number
    //      using a loop

    std::cout << "Today we will play a guessing game." << std::endl;

    // variable declarations
    const int MIN_GUESS = 0;
    const int MAX_GUESS = 9;
    int loopCounter = 0;
    int randomNumber;
    std::string userGuess;
    int userGuessInt;

    // random number generation
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(MIN_GUESS, MAX_GUESS);
    randomNumber = idist(rgen);

    // process
    while (true) {
        // input
        std::cout << "" << std::endl;
        std::cout << "Enter a number between 0-9: ";
        std::cin >> userGuess;
        std::cout << "" << std::endl;

        // process
        try {
            userGuessInt = std::stoi(userGuess);

            if (userGuessInt >= MIN_GUESS && userGuessInt <= MAX_GUESS) {
                // process
                loopCounter = loopCounter + 1;

                if (userGuessInt == randomNumber) {
                    break;
                } else if (userGuessInt > randomNumber) {
                    std::cout << "Your guess is too high, "
                              <<"try again." << std::endl;
                } else if (userGuessInt < randomNumber) {
                    std::cout << "Your guess is too low, "
                              <<"try again." << std::endl;
                } else {
                    std::cout << "Error, try again." << std::endl;
                }
            } else {
                // output
                std::cout << "Your guess must be between " << MIN_GUESS
                          << "-" << MAX_GUESS << ", try again." << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "That's not a number! Try again." << std::endl;
        }
    }

    std::cout << "" << std::endl;
    std::cout << "Correct! It took you " << loopCounter << " time(s) to guess "
              << "the number." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Thanks for playing!" << std::endl;
}
