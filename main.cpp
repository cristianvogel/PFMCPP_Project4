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



#include <math.h> // I needed to do an ABS function... and a twoExp
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
   
    FloatType& add ( float );
    FloatType& subtract ( float );
    FloatType& multiply ( float );
    FloatType& divide ( float );
};

FloatType& FloatType::add ( float x )
{
    *pointerToFloatValue += x;
    return *this;
}

FloatType& FloatType::subtract ( float y ) 
{ 
    *pointerToFloatValue -= y;
    return *this; 
}

FloatType& FloatType::multiply ( float y) 
{ 
    *pointerToFloatValue *= y;
    return *this; 
}

FloatType& FloatType::divide ( float y ) 
{ 
    if (abs(y) > 0) *pointerToFloatValue /= y;    
    
    std::cout << "Divide-by-zero warning  " << std::endl;
    *pointerToFloatValue /= 0;
    return *this;      
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

    DoubleType& add ( double);
    DoubleType& subtract ( double);
    DoubleType& multiply ( double);
    DoubleType& divide ( double);
};

DoubleType& DoubleType::add ( double y)
{
    *pointerToDoubleValue += y;
    return *this;
}

DoubleType& DoubleType::subtract ( double y) 
{ 
    *pointerToDoubleValue -= y;
    return *this; 
}

DoubleType& DoubleType::multiply ( double y) 
{ 
    *pointerToDoubleValue *= y;
    return *this; 
}

DoubleType& DoubleType::divide ( double y) 
{ 
    if (abs(y) > 0) *pointerToDoubleValue /= y;    
    
    std::cout << "Divide-by-zero warning  " << std::endl;
    *pointerToDoubleValue /= 0;
    return *this;      
}

struct IntType
{
    int* pointerToIntValue = nullptr;

     // default constructor assigns heap primitive if no value sent in
    IntType() {
        pointerToIntValue = new int();
    }
   
    IntType( int intIn )
    {
        pointerToIntValue = new int ( intIn );
    }
    ~IntType()
    {
        delete pointerToIntValue;
        pointerToIntValue = nullptr;
    }

    IntType& add ( int );
    IntType& subtract ( int );
    IntType& multiply ( int );
    IntType& divide ( int );
};

IntType& IntType::add ( int y )
{
    *pointerToIntValue += y;
    return *this;
}

IntType& IntType::subtract ( int y ) 
{ 
    *pointerToIntValue -= y;
    return *this;
}

IntType& IntType::multiply ( int y ) 
{ 
    *pointerToIntValue *= y;
    return *this; 
}

IntType& IntType::divide ( int y ) 
{ 
    if (y != 0) *pointerToIntValue /=y; 
    
    std::cout << "Cannot Divide Int by Zero! " << std::endl;
    *pointerToIntValue = 0;
    return *this;
}

#include <iostream>

int main()
{   
    HeapA heapA ;

    FloatType ft ( 0.137f );
    DoubleType dt (0.55 );
    IntType it ( 137 ) ;

    std::cout << "FloatType add result=" << *( ft.add( 2.0f ).pointerToFloatValue ) << std::endl;
    std::cout << "FloatType subtract result=" << *( ft.subtract( 2.0f ).pointerToFloatValue ) << std::endl;
    std::cout << "FloatType multiply result=" << *( ft.multiply( 2.0f ).pointerToFloatValue ) << std::endl;
    std::cout << "FloatType divide result=" << *( ft.divide( 0.0f).pointerToFloatValue ) << std::endl << std::endl;

    std::cout << "DoubleType add result=" << *( dt.add(2.0).pointerToDoubleValue ) << std::endl;
    std::cout << "DoubleType subtract result=" << *(dt.subtract(2.0).pointerToDoubleValue) << std::endl;
    std::cout << "DoubleType multiply result=" << *(dt.multiply(2.0).pointerToDoubleValue) << std::endl;
    std::cout << "DoubleType divide result=" << *(dt.divide(0).pointerToDoubleValue) << std::endl << std::endl;

    std::cout << "IntType add result=" << *( it.add(2).pointerToIntValue ) << std::endl;
    std::cout << "IntType subtract result=" << *( it.subtract(2).pointerToIntValue ) << std::endl;
    std::cout << "IntType multiply result=" << *( it.multiply(2).pointerToIntValue ) << std::endl;
    std::cout << "IntType divide result=" << *( it.divide(0).pointerToIntValue ) << std::endl << std::endl;

    std::cout << "good to go!" << std::endl;
}
