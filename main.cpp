/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */

struct A { };

struct HeapA 
{
    A* pointerToA = nullptr;
    
    HeapA() {
        pointerToA = new A();
    }
    
    ~HeapA()
    {
        delete pointerToA;
        pointerToA = nullptr;
    }
};


 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers  
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write some add/subtract/divide/multiply member functions for each type that take your 3 UDTs
         for example, IntType::divide(const DoubleType& dt);
 
 5) print out the results with some creative couts 
    i.e.
         FloatType ft(0.1f);
         IntType it(3);
         std::cout << "adding 3 and subtracting 'it' from 'ft' results in the following value: " << *ft.add(2.f).subtract( it ).value << std::endl;  //note the dereference of the `value` member of `ft`
 
 6) Don't let your heap-allocated owned type leak!
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */



#include <math.h> // I needed to do an ABS function...
#include <iostream> // to print a divide-by-zero console message

struct FloatType
{
    float* pointerToFloatValue = nullptr;

    // default constructor assigns heap primitive if no value sent in
    FloatType() {
        pointerToFloatValue = new float();
     } 

    FloatType(float floatIn )
    {
        pointerToFloatValue = new float( floatIn );
    }
    
    ~FloatType()
    {
        delete pointerToFloatValue;
        pointerToFloatValue = nullptr;
    }
   
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
    
    std::cout << "Divide-by-zero warning  " << std::endl;
    return (x/y);      
}

struct DoubleType
{
    double* pointerToDoubleValue = nullptr;

    // default constructor assigns heap primitive if no value sent in
    DoubleType() {
        pointerToDoubleValue = new double();
     } 

    DoubleType(double doubleIn )
    {
        pointerToDoubleValue = new double( doubleIn );
    }
    
    ~DoubleType()
    {
        delete pointerToDoubleValue;
        pointerToDoubleValue = nullptr;
    }

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
    
    std::cout << "Divide-by-zero warning  " << std::endl;
    return (x/y);      
}

struct IntType
{
    int* pointerToInt = nullptr;

     // default constructor assigns heap primitive if no value sent in
    IntType() {
        pointerToInt = new int();
    }
   
    IntType( int intIn )
    {
        pointerToInt = new int ( intIn );
    }
    ~IntType()
    {
        delete pointerToInt;
        pointerToInt = nullptr;
    }

    int add (int, int);
    int subtract ( int, int);
    int multiply ( int, int);
    int divide (int, int);
};

int IntType::add (int x, int y)
{
    int result = (x+y);
    return result;
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
    
    std::cout << "Cannot Divide Int by Zero! " << std::endl;
    return 0;
}

#include <iostream>

int main()
{   
    HeapA heapA ;

    FloatType ft ( 0.137f );
    DoubleType dt (0.55 );
    IntType it ( 137 ) ;

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
