/*
 Project 4 - Part 1

NAME YOUR BRANCH "PART 1"

 video: Chapter 2 Part 7
 Returning Values tasks 
 
 1) write 3 UDTs named FloatType, DoubleType, IntType.
 
 2) give each UDT the following member functions:
        add( lhs, rhs );
        subtract( lhs, rhs );
        multiply( lhs, rhs );
        divide( lhs, rhs );
 
 3) make them return the correct primitive type. e.g. if you're implementing the FloatType::add function, your implementation would start like this:
        float FloatType::add( float lhs, float rhs )
 
 4) declare a few instances of each class in main() and call the member functions with the appropriate arguments.
        FloatType ft;
        auto result = ft.add(3.2f, 23.f );
 
 5) print out those results using std::cout:
        std::cout "result of ft.add(): " << result << std::endl;
 
 6) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Wait for my code review.
 */
#include <math.h> // I needed to do an ABS function...
#include <iostream> // to print a divide-by-zero console message
struct FloatType
{
    float add (float, float);
    float subtract ( float, float);
    float multiply ( float, float);
    float divide (float, float);
};

float FloatType::add (float x, float y)
{
    return (x+y);
}

float FloatType::subtract (float x, float y) 
{ 
    return (x-y); 
}

float FloatType::multiply (float x, float y) 
{ 
    return (x*y); 
}

float FloatType::divide (float x, float y) 
{ 
    if (abs(y) > 0) return (x/y);    
    else 
    {
        std::cout << "Divide-by-zero warning  " << std::endl;
        return (x/y);      
    }
}

struct DoubleType
{
    double add (double, double);
    double subtract ( double, double);
    double multiply ( double, double);
    double divide (double, double);
};

double DoubleType::add (double x, double y)
{
    return (x+y);
}

double DoubleType::subtract (double x, double y) 
{ 
    return (x-y); 
}

double DoubleType::multiply (double x, double y) 
{ 
    return (x*y); 
}

double DoubleType::divide (double x, double y) 
{ 
    if (abs(y) > 0) return (x/y);    
    else 
    {
        std::cout << "Divide-by-zero warning  " << std::endl;
        return (x/y);      
    }
     
}

struct IntType
{
    int add (int, int);
    int subtract ( int, int);
    int multiply ( int, int);
    int divide (int, int);
};

int IntType::add (int x, int y)
{
    return (x+y);
}

int IntType::subtract (int x, int y) 
{ 
    return (x-y); 
}

int IntType::multiply (int x, int y) 
{ 
    return (x*y); 
}

int IntType::divide (int x, int y) 
{ 
    if (y != 0) return (x/y);

    else 
    {
        std::cout << "Cannot Divide Int by Zero! " << std::endl;
        return 0;
    }
}

#include <iostream>

int main()
{   
    FloatType ft;
    DoubleType dt;
    IntType it;

    std::cout << "FloatType add result=" << (ft.add(2.0f, 2.0f)) << std::endl;
    std::cout << "FloatType subtract result=" << (ft.subtract(2.0f, 2.0f)) << std::endl;
    std::cout << "FloatType multiply result=" << (ft.multiply(2.0f, 2.0f)) << std::endl;
    std::cout << "FloatType divide result=" << (ft.divide(2.0f, 0.0f)) << std::endl << std::endl;

    std::cout << "DoubleType add result=" << (dt.add(2.0, 2.0)) << std::endl;
    std::cout << "DoubleType subtract result=" << (dt.subtract(2.0, 2.0)) << std::endl;
    std::cout << "DoubleType multiply result=" << (dt.multiply(2.0, 2.0)) << std::endl;
    std::cout << "DoubleType divide result=" << (dt.divide(2.0, 0)) << std::endl << std::endl;

    std::cout << "IntType add result=" << (it.add(2, 2)) << std::endl;
    std::cout << "IntType subtract result=" << (it.subtract(2, 2)) << std::endl;
    std::cout << "IntType multiply result=" << (it.multiply(2, 2)) << std::endl;
    std::cout << "IntType divide result=" << (it.divide(2, 0 )) << std::endl << std::endl;

    std::cout << "good to go!" << std::endl;
}
