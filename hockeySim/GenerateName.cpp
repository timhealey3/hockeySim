#include "GenerateName.h"

GenerateName::GenerateName()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

GenerateName::~GenerateName()
{
}

void GenerateName::readNameFile()
{
    std::cout << "FILE::Reading name file started" << "\n";
    // get first names
    std::ifstream file("firstName.txt");
    std::string str;
    while (std::getline(file, str)) {
        firstNames.push_back(str);
    }
    file.close();

    // get last names
    std::ifstream fileLast("names.txt");
    std::string strLast;
    while (std::getline(fileLast, strLast)) {
        lastNames.push_back(strLast);
    }
    fileLast.close();

    std::cout << "FILE::Reading name file ended" << "\n";
}

std::string GenerateName::generateName()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int firstNameIndex = std::rand() % firstNames.size();
    int lastNameIndex = std::rand() % lastNames.size();
    std::string firstNameString = firstNames[firstNameIndex];
    std::string lastNameString = lastNames[lastNameIndex];
    std::string result = firstNameString + " " + lastNameString;
    return result;
}

std::string GenerateName::generateFirstName()
{
    int firstNameIndex = std::rand() % firstNames.size();
    std::string firstNameString = firstNames[firstNameIndex];
    return firstNameString;
}

std::string GenerateName::generateLastName()
{
    int lastNameIndex = std::rand() % lastNames.size();
    std::string lastNameString = lastNames[lastNameIndex];
    return lastNameString;
}
