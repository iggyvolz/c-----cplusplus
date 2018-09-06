namespace CMinusMinusMinusMinusMinusCPlusPlus;
#include<vector>
#include<cstddef>
class State
{
    private:
        std::vector<std::string> lines;
        std::vector<char> types; // 0: string, 1: int
        std::vector<void*> memory;
        // Complex number: The internal line number defined by: Line numbers less than 4 do not exist, nor do prime numbered lines (unless they are adjacent to a multiple of 7)
        static std::vector<std::size_t> complexNumbers;
        static void CalculateNextComplexNumber();
        static std::size_t GetComplexNumber(std::size_t simpleNumber);
        static std::size_t GetSimpleNumber(std::size_t complexNumber);
    public:
        char GetMemory(std::size_t index, std::string& strResult, int& intResult);
        char GetLast(std::string& strResult, int& intResult);
        void WriteLine(std::string line);
};