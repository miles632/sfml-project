#include <unistd.h>
#include <iostream>
#include <string>

std::string GetCurrentDirectory()
{
    char currentDirectory[FILENAME_MAX];

    if (getcwd(currentDirectory, sizeof(currentDirectory)) != nullptr){
        return std::string(currentDirectory);
    } 
    else {
        return "";
    }
}