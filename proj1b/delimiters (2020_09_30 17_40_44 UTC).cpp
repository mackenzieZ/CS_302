//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------
#include "config.h"

#include <iostream>
#include <fstream>

#if LAB6_TEST1
#   include "StackLinked.cpp"
#else
#   include "StackArray.cpp"
#endif

//--------------------------------------------------------------------

int strlen(const std::string word){
    int counter =0;
    int i = 0;
    while(word[i] != '\0'){
        counter++;
        i++;
    }
    return counter;
}  

bool delimitersOk ( const std::string &expression, std::ofstream &file);


//--------------------------------------------------------------------

int main()
{
    std::string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars
    std::ofstream outputFile;
    outputFile.open("DelimitersOutput.txt");

    std::cout << "This program checks for properly matched delimiters."
         << std::endl;

    for(int i = 0; i < 5; i++)
    {
        std::cout << "Enter delimited expression (<EOF> to quit) : "
             << std::endl;

        // Read in one line
        inputLine = "";
        std::cin.get(ch);
        while( std::cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            std::cin.get(ch);
        }

        /*if( !std::cin ){ 
           // Reached EOF: stop processing
            break;
        }*/
        
        if ( delimitersOk (inputLine, outputFile) )
            std::cout << "Valid" << std::endl;
        else
            std::cout << "Invalid" << std::endl;
        
    }
    
    outputFile.close();
    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below
bool delimitersOk(const std::string &expression, std::ofstream &file){
    StackLinked<char> s1;
    bool valid;
    for(std::string::size_type i = 0; i < strlen(expression); i++){
        file << expression[i]; 
        valid = false;
        switch(expression[i]){
            case '[':  s1.push(expression[i]); valid = false; break;
            case '(':  s1.push(expression[i] ); valid = false; break;
            case '{':  s1.push(expression[i] ); valid = false; break;
            case ']':  if(s1.pop() == '['){valid = true;} break;
            case ')':  if(s1.pop() == '('){valid = true;} break;
            case '}':  if(s1.pop() == '('){valid = true;} break;
        }
    }
    file << " is " << valid << '\n';
    return valid;
}



