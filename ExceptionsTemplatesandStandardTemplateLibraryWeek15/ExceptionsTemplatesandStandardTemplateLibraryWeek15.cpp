#include <iostream>
#include <vector>

using namespace std;




class invalidCharacterExcpeption
{

};

class invalidRangeException
{

};

class caseConversionException
{

};



char character(char start, int offset)
{
    int startAsciiValue = int(start);
    int target = startAsciiValue + offset;


    try {
        if (startAsciiValue < 65 || (startAsciiValue > 90 && startAsciiValue < 97) || startAsciiValue > 122)
        {
            throw invalidCharacterExcpeption();
        }

        else if (target < 65 || (target > 90 && target < 97) || target > 122)
        {
            throw invalidRangeException();
        }

        else if ((target >= 65 && target <= 90 && startAsciiValue >= 95 && startAsciiValue <= 122) || (target >= 95 && target <= 122 && startAsciiValue >= 65 && startAsciiValue <= 90))
        {
            throw caseConversionException();
        }
    }

    catch (invalidCharacterExcpeption exception1)
    {
        cout << " Invalid Character Exception " << endl;
        return ' ';
    }
    catch (invalidRangeException exception2)
    {
        cout << " Invalid Range Exception " << endl;
        return ' ';
    }
    catch (caseConversionException exception3)
    {
        cout << " Cannot make case changes from upper to lower or otherwise " << endl;
        return ' ';
    }

    return char(target);
}

int main()
{
    cout << character('a', 1) << endl;
    cout << character('a', -1) << endl;
    cout << character('Z', -1) << endl;
    cout << character('?', 5) << endl;
    cout << character('A', 32) << endl;
}