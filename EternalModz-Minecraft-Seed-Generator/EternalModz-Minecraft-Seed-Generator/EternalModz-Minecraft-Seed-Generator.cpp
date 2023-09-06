#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <random>
#include <cctype> // Include for handling letter options

// ANSI escape codes for text color and formatting
const std::string YELLOW_COLOR = "\033[1;33m";
const std::string GREEN_COLOR = "\033[1;32m";
const std::string LAVENDER_PURPLE_COLOR = "\033[38;2;120;66;245m"; // Lavender Purple (RGB: 120, 66, 245)
const std::string BOLD_TEXT = "\033[1m";
const std::string RESET_COLOR = "\033[0m";

// Function to generate a random numeric seed for Minecraft Java within the specified range
std::string generateJavaSeed() {
    std::random_device rd;
    std::mt19937_64 gen(rd());

    // Define the numeric range for Java seeds
    long long minSeed = -9223372036854775807LL; // Smallest possible numeric seed
    long long maxSeed = 9223372036854775807LL;  // Largest possible numeric seed

    std::uniform_int_distribution<long long> dis(minSeed, maxSeed);

    long long generatedSeed = dis(gen);

    return std::to_string(generatedSeed);
}

// Function to generate a random numeric seed for Minecraft Bedrock within the specified range
std::string generateBedrockSeed() {
    std::random_device rd;
    std::mt19937_64 gen(rd());

    // Define the numeric range for Bedrock seeds
    long long minSeed = -9223372036854775807LL; // Smallest possible numeric seed
    long long maxSeed = 9223372036854775807LL;  // Largest possible numeric seed

    std::uniform_int_distribution<long long> dis(minSeed, maxSeed);

    long long generatedSeed = dis(gen);

    return std::to_string(generatedSeed);
}

// Function to generate a random numeric seed for Minecraft Legacy Console within the specified range
std::string generateLegacyConsoleSeed() {
    std::random_device rd;
    std::mt19937_64 gen(rd());

    // Define the numeric range for Legacy Console seeds
    long long minSeed = -9223372036854775807LL; // Smallest possible numeric seed
    long long maxSeed = 9223372036854775807LL;  // Largest possible numeric seed

    std::uniform_int_distribution<long long> dis(minSeed, maxSeed);

    long long generatedSeed = dis(gen);

    return std::to_string(generatedSeed);
}

// Function to generate a random seed containing random digits from 0 to 9
std::string generateRandomNumericSeed(int maxLength) {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the characters that can be included in the seed
    const std::string seedCharacters = "0123456789";

    std::uniform_int_distribution<int> charIndexDist(0, seedCharacters.size() - 1);

    std::string generatedSeed;

    for (int i = 0; i < maxLength; ++i) {
        int charIndex = charIndexDist(gen);
        generatedSeed += seedCharacters[charIndex];
    }

    return generatedSeed;
}

// Function to display a rainbow-colored progress bar
void displayGradientProgressBar(int progress) {
    const int numSegments = 40;
    const int segmentWidth = 100 / numSegments;
    const int numColors = 7;

    // Define RGB values for the gradient colors
    int colors[numColors][3] = {
        {255, 0, 0},       // Red
        {255, 165, 0},     // Orange
        {255, 255, 0},     // Yellow
        {0, 128, 0},       // Green
        {0, 0, 255},       // Light Blue
        {0, 0, 128},       // Dark Blue
        {128, 0, 128}      // Purple
    };

    // Calculate the current color based on progress
    int currentColorIndex = static_cast<int>((progress / 100.0) * (numColors - 1));

    // Calculate the current color's RGB values
    int r = colors[currentColorIndex][0];
    int g = colors[currentColorIndex][1];
    int b = colors[currentColorIndex][2];

    for (int i = 0; i < numSegments; ++i) {
        int segmentProgress = i * segmentWidth;
        if (segmentProgress <= progress) {
            // Set the text color for the segment
            std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m=";
        }
        else {
            // Reset text color for empty segments
            std::cout << " ";
        }
    }

    // Reset text color and display progress percentage
    std::cout << "\033[0m" << " " << progress << "%" << "\r";
    std::cout.flush();
}

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    char choice; // Change choice to char to handle both numbers and letters
    std::string generatedSeed; // Declare the variable here

    do {
        std::cout << "Minecraft Seed Generator:" << std::endl;
        std::cout << YELLOW_COLOR << "1. Minecraft Java (J)" << RESET_COLOR << std::endl;
        std::cout << YELLOW_COLOR << "2. Minecraft Bedrock (B)" << RESET_COLOR << std::endl;
        std::cout << YELLOW_COLOR << "3. Minecraft Legacy Console (L)" << RESET_COLOR << std::endl;
        std::cout << YELLOW_COLOR << "4. Exit (E)" << RESET_COLOR << std::endl;
        std::cout << YELLOW_COLOR << "5. About This Tool (A)" << RESET_COLOR << std::endl;
        std::cout << "Enter your choice (1-5 or J, B, L, E, A): ";
        std::cin >> choice;
        choice = tolower(choice); // Convert choice to lowercase for uniform comparison

        switch (choice) {
        case '1':
        case 'j':
            // Minecraft Java
            std::cout << "Generating a Java seed..." << std::endl;
            for (int progress = 0; progress <= 100; progress += 5) {
                displayGradientProgressBar(progress);
                std::this_thread::sleep_for(std::chrono::milliseconds(50)); // 50ms delay
            }
            generatedSeed = generateJavaSeed();
            if (generatedSeed[0] != '-') {
                generatedSeed = "-" + generatedSeed;
            }
            std::cout << GREEN_COLOR << "Generated Java seed: " << BOLD_TEXT << generatedSeed << RESET_COLOR << std::endl;
            break;
        case '2':
        case 'b':
            // Minecraft Bedrock
            std::cout << "Generating a Bedrock seed..." << std::endl;
            for (int progress = 0; progress <= 100; progress += 5) {
                displayGradientProgressBar(progress);
                std::this_thread::sleep_for(std::chrono::milliseconds(50)); // 50ms delay
            }
            generatedSeed = generateBedrockSeed();
            if (generatedSeed[0] != '-') {
                generatedSeed = "-" + generatedSeed;
            }
            std::cout << GREEN_COLOR << "Generated Bedrock seed: " << BOLD_TEXT << generatedSeed << RESET_COLOR << std::endl;
            break;
        case '3':
        case 'l':
            // Minecraft Legacy Console
            std::cout << "Generating a Legacy Console seed..." << std::endl;
            for (int progress = 0; progress <= 100; progress += 5) {
                displayGradientProgressBar(progress);
                std::this_thread::sleep_for(std::chrono::milliseconds(50)); // 50ms delay
            }
            generatedSeed = generateLegacyConsoleSeed();
            if (generatedSeed[0] != '-') {
                generatedSeed = "-" + generatedSeed;
            }
            std::cout << GREEN_COLOR << "Generated Legacy Console seed: " << BOLD_TEXT << generatedSeed << RESET_COLOR << std::endl;
            break;
        case '4':
        case 'e':
            // Exit
            std::cout << "Exiting the program." << std::endl;
            break;
        case '5':
        case 'a':
            // About This Tool
            std::cout << LAVENDER_PURPLE_COLOR << "Tool Version: 1.1.0" << std::endl;
            std::cout << "Tool Creator / Developer: EternalModz" << std::endl;
            std::cout << "Source Code: https://github.com/EternalModz/Minecraft-Universal-Seed-Generator" << std::endl;
            std::cout << "License: GNU Affero General Public License v3.0" << std::endl;
            std::cout << "YouTube: https://youtube.com/@EternalModzLive" << std::endl;
            std::cout << "Thanks for using my tool!" << std::endl;
            std::cout << LAVENDER_PURPLE_COLOR << "Credits: UtterEvergreen1 & jerrinth3glitch" << RESET_COLOR << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    } while (choice != '4' && choice != 'e');

    return 0;
}