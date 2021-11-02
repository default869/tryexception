#include <iostream>
#include <string>
using namespace std;

class Exception
{
protected:
    string text;

public:

    virtual string Print() = 0;
};

class MathExceptions :public Exception
{
public:

    MathExceptions()
    {
        text = "Error!";
    }

    MathExceptions(string text) 
    { 
        Exception::text = text;
    }

    string Print() 
    { 
        return text; 
    }
};

class DivideByZero :public MathExceptions
{
public:

    DivideByZero(string text) 
    {
        MathExceptions::text = text;
    }

    string Print()
    {
        return text;
    }
};

class WrongIndex :public Exception
{
public:

    WrongIndex(string text)
    {
        Exception::text = text;
    }

    string Print()
    { 
        return text; 
    }
};

void WrongIndexFunc()
{
    cout << "Finding index: " << endl;
    int arr[10];
    int index;
    for (int i = 0; i < 10; i++) arr[i] = rand() % 100;
    cin >> index;
    if (index < 0) throw WrongIndex("Index less than 0!");
    if (index > 10) throw WrongIndex("Index more than 10!");
    else cout << arr[index] << endl;
}

void DevideByNull()
{
    cout << "Dividing:" << endl;
    int a, b;
    cin >> a;
    cin >> b;
    if (b == 0) throw DivideByZero("Cannot be divided by 0!");
    else 
    {
        double c = a / b;
        cout << c << endl;
    }
}

void main()
{
    try
    {
        WrongIndexFunc(); 
        DevideByNull(); 
    }
    catch (WrongIndex test)
    {
        cout << test.Print() << endl;
    }
    catch (DivideByZero test)
    {
        cout << test.Print() << endl;
    }
}