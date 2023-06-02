#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>
using namespace std;

class HexFormatException : public runtime_error
{
public:
  HexFormatException(char ch) : runtime_error("Hex number format error")
  {
    this->ch = ch;
  }

  char getCh()
  {
    return ch;
  }

private:
  char ch;
};

// The function returns an int for a hex digit. 
// Throws HexFormatException(ch) if the hex character is invalid
int convertHexToDec(char ch)
{
  ch = toupper(ch); 
    if (ch >= 'A' && ch <= 'F')
        return 10 + ch - 'A';
    if (ch > 'A' && ch > 'F')
        throw HexFormatException(ch);
    else
        return ch - '0';
}

int hex2Dec(const string& hexString)
{
  int value = convertHexToDec(hexString[0]);
  for (int i = 1; i < hexString.size(); i++)
  {
    value = value * 16 + convertHexToDec(hexString[i]);
  }

  return value;
}

int main()
{
  string hexString;
  int convertedHex;

  cout << "Enter a hex number: ";
  cin >> hexString;
  
  try {
    convertedHex = hex2Dec(hexString);
    cout << "The decimal value for hex number " << hexString << " is " << hex2Dec(hexString) << endl;
  }

  catch(runtime_error& ex) {
    cout << "Not a hex number ";
  }

  return 0;
}