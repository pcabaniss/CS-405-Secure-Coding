// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Creating a custom exception class
struct Custom : public std::exception {
    const char* what() const throw ()
    {
        return "This is a custom exception!!";
    }

};

bool do_even_more_custom_application_logic()
{


    std::cout << "Running Even More Custom Application Logic." << std::endl;

    // Throw a standard exception
    throw std::exception();

    return true;
}
void do_custom_application_logic()
{

    std::cout << "Running Custom Application Logic." << std::endl;

    // Try-catch block to call an exception
    try {
        if(do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (std::exception error) {
        std::cout << "An exception has been called!" << std::endl;
        std::cout << error.what() << std::endl;
    }

    // Call custom exception
    throw (Custom());

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // Check if zero is denominator
    if (den == 0) {
        throw std::runtime_error("Cannot divide by zero!");
    }
    return (num / den);
}

void do_division() noexcept
{

    float numerator = 10.0f;
    float denominator = 0;
    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::exception& error) {
        // Use cerr to display error message and location of error
        std::cerr << "Error in do_division(): " << error.what() << std::endl;
    }

}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // Catching all of the exceptions:
    try {
        do_division();
        do_custom_application_logic();
    }
    catch (Custom& error) {
        std::cout << "Error was thrown: " << error.what() << std::endl;
    }
    catch (std::exception error) {
        std::cout << "Error was thrown: " << error.what() << std::endl;
    }
    catch (...) {
        std::cout << "An unknown error has occurred.\n";
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu