#include <chrono>
#include <ctime>
#include <iostream>

// #include "account_details.cpp"
using namespace std;
std::string getCurrentTimestamp() {
    // Get the current time point
    auto currentTime = std::chrono::system_clock::now();

    // Convert the time point to a time_t object
    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);

    // Convert the time_t object to a string timestamp
    std::string timestamp = std::ctime(&time);

    // Remove the newline character from the timestamp
    timestamp.erase(timestamp.length() - 1);

    return timestamp;
}

std::string getCurrentDate() {
    // Get the current time point
    auto currentTime = std::chrono::system_clock::now();

    // Convert the time point to a time_t object
    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);

    // Convert the time_t object to a tm structure (local time)
    std::tm* timeInfo = std::localtime(&time);

    // Format the date components as a string
    char buffer[11];  // For "YYYY-MM-DD\0" (10 characters + null terminator)
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeInfo);

    return buffer;
}

// Function to calculate the age based on the birth date and the current date
float calculateAge(const std::string& birthDate) {
    // Get the current time point
    auto currentTime = std::chrono::system_clock::now();

    // Convert the time point to a time_t object
    std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);

    // Parse the birth date string to extract year, month, and day
    int birthYear, birthMonth, birthDay;
    std::sscanf(birthDate.c_str(), "%d-%d-%d", &birthYear, &birthMonth, &birthDay);

    // Convert the birth date components to a tm structure (local time)
    std::tm birthTimeInfo = {0};
    birthTimeInfo.tm_year = birthYear - 1900;
    birthTimeInfo.tm_mon = birthMonth - 1;
    birthTimeInfo.tm_mday = birthDay;

    // Convert the tm structure to a time_t object
    std::time_t birthTime_t = std::mktime(&birthTimeInfo);

    // Calculate the difference in seconds between birth date and current date
    std::chrono::seconds ageSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - std::chrono::system_clock::from_time_t(birthTime_t));

    // Calculate the age in years
    float ageYears = ageSeconds.count() / (60 * 60 * 24 * 365);

    float ageYears;
}

// int main() {
//     std::string timestamp = getCurrentTimestamp();

//     std::cout << "Current Timestamp: " << timestamp << std::endl;

//     return 0;
// }
