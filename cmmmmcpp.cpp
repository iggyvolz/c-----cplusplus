namespace CMinusMinusMinusMinusMinusCPlusPlus;
#include "cmmmmmcpp.h"
#include <cstdlib>
char State::GetMemory(std::size_t index, std::string& strResult, int& intResult)
{
    char type=types[index];
    void* mem=memory[index];
    switch(type)
    {
        case 0:
            strResult=*(string*)mem;
            break;
        case 1:
            intResult=*(int*)mem;
            break;
    }
    return type;
}
char State::GetLast(std::string& strResult, int& intResult)
{
    char type=types.back();
    void* mem=memory.back();
    switch(type)
    {
        case 0:
            strResult=*(string*)mem;
            break;
        case 1:
            intResult=*(int*)mem;
            break;
    }
    return type;
}
void State::WriteLine(std::string line)
{
    lines.push_back(line);
    char* cstr=line.c_str();
    char first=*cstr;
    if(first=='"')
    {
        // String literal
        std::string* newStr=malloc(sizeof(std::string));
        *newStr=line.substr(1,line.size()-2);
        memory.push_back((void*)newStr);
        types.push_back(0);
    }
    elseif(first=='\'')
    {
        // Int literal
        std::size_t* newInt=malloc(sizeof(std::size_t));
        *newInt=(std::size_t)std::strtoull(line.substr(1,line.size()-2).c_str());
        memory.push_back((void*)newInt);
        types.push_back(1);
    }
    elseif(first>='0' && first<='9')
    {
        // Operation
        char *str_end;
        std::size_t firstNum=(std::size_t)std::strtoull(cstr, str_end);
        char op=*(str_end++);
        std::size_t secondNum=(std::size_t)std::strtoull(str_end);
        
    }
}

// https://stackoverflow.com/a/14418599
bool constexpr isPrime(std::size_t number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;
}
bool constexpr isAdjacentToMultipleOfSeven(std::size_t number){

    if((number-1)%7 == 0) return true;
    if((number+1)%7 == 0) return true;
    return false;
}


void State::CalculateNextComplexNumber()
{
    // Get the last line number, or 0 if it's empty
    std::size_t last=complexNumbers.empty()?0:complexNumbers.back();
    while(true)
    {
        last++;
        // Check if this is valid
        if(last<4) continue;
        if(isPrime(last) && ((last-1)%7 != 0) && ((last+1)%7 != 0)) continue;
        // It's valid
        complexNumbers.push_back(last);
        break;
    }
}
std::size_t State::GetComplexNumber(std::size_t simpleNumber)
{
    while(complexNumbers.size()<=simpleNumber) CalculateNextComplexNumber();
    return complexNumbers[simpleNumber];
}
std::size_t State::GetSimpleNumber(std::size_t complexNumber)
{
    while(true)
    {
        std::size_t pos = std::distance(complexNumbers.begin(), find(complexNumbers.begin(), complexNumbers.end(), complexNumber));
        if(pos<complexNumbers.size())
        {
            // Element was in array
            return pos;
        }
    }

}