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



#include <math.h> // I needed to do an ABS function
#include <iostream> // to print a divide-by-zero console message

//forward declarations of other types for overloaded member functions
struct DoubleType;
struct IntType;

struct FloatType
{
    float* pointerToFloatValue = nullptr;

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
    FloatType& add ( const DoubleType& );
    FloatType& subtract ( const DoubleType& );
    FloatType& multiply ( const DoubleType& );
    FloatType& divide ( const DoubleType& );
    FloatType& add ( const IntType& );
    FloatType& subtract ( const IntType& );
    FloatType& multiply ( const IntType& );
    FloatType& divide ( const IntType& );
};

FloatType& FloatType::add ( const float x )
{
    *pointerToFloatValue += x;
    return *this;
}

FloatType& FloatType::subtract ( const float y ) 
{ 
    *pointerToFloatValue -= y;
    return *this; 
}

FloatType& FloatType::multiply ( const float y) 
{ 
    *pointerToFloatValue *= y;
    return *this; 
}

FloatType& FloatType::divide ( const float y ) 
{ 
    if (abs(y) > 0) 
    { 
        *pointerToFloatValue /= y; 
    } 
    else 
    { 
        std::cout << "Divide-by-zero warning  " << std::endl;
    }   

    return *this;      
}

struct DoubleType
{
    double* pointerToDoubleValue = nullptr;

    DoubleType(double doubleIn )
    {
        pointerToDoubleValue = new double( doubleIn );
    }
    
    ~DoubleType()
    {
        delete pointerToDoubleValue;
        pointerToDoubleValue = nullptr;
    }

    DoubleType& add ( double );
    DoubleType& subtract ( double );
    DoubleType& multiply ( double );
    DoubleType& divide ( double );
    DoubleType& add ( const FloatType& );
    DoubleType& subtract ( const FloatType& );
    DoubleType& multiply ( const FloatType& );
    DoubleType& divide ( const FloatType& );
    DoubleType& add ( const IntType& );
    DoubleType& subtract ( const IntType& );
    DoubleType& multiply ( const IntType& );
    DoubleType& divide ( const IntType& );
};

DoubleType& DoubleType::add ( const double y)
{
    *pointerToDoubleValue += y;
    return *this;
}

DoubleType& DoubleType::subtract ( const double y) 
{ 
    *pointerToDoubleValue -= y;
    return *this; 
}

DoubleType& DoubleType::multiply ( const double y) 
{ 
    *pointerToDoubleValue *= y;
    return *this; 
}

DoubleType& DoubleType::divide ( const double y) 
{ 
    if (abs(y) > 0) 
    {
        *pointerToDoubleValue /= y;    
    } 
    else 
    {
        std::cout << "Divide-by-zero warning  " << std::endl;
    }

    return *this;      
}

struct IntType
{
    int* pointerToIntValue = nullptr;
   
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
    IntType& divide ( const IntType& );
    IntType& add ( const FloatType& );
    IntType& subtract ( const FloatType& );
    IntType& multiply ( const FloatType& );
    IntType& divide ( const FloatType& );
    IntType& add ( const DoubleType& );
    IntType& subtract ( const DoubleType& );
    IntType& multiply ( const DoubleType& );
    IntType& divide ( const DoubleType& );
};

IntType& IntType::add ( const int y )
{
    *pointerToIntValue += y;
    return *this;
}

IntType& IntType::subtract ( const int y ) 
{ 
    *pointerToIntValue -= y;
    return *this;
}

IntType& IntType::multiply ( const int y ) 
{ 
    *pointerToIntValue *= y;
    return *this; 
}

IntType& IntType::divide ( const int y ) 
{ 
    if (y != 0 ) 
    {
        *pointerToIntValue /=y; 
    } 
    else 
    {
        std::cout << "Cannot Divide Int by Zero! " << std::endl;
    }

    return *this;
}

//additional member functions as per instruction 4
FloatType& FloatType::add( const DoubleType& dt )
{
    return add( *dt.pointerToDoubleValue );
}

FloatType& FloatType::subtract( const DoubleType& dt ) 
{ 
    return subtract( *dt.pointerToDoubleValue ); 
}

FloatType& FloatType::multiply( const DoubleType& dt) 
{ 
    *pointerToFloatValue *= *dt.pointerToDoubleValue;
    return multiply( *dt.pointerToDoubleValue ); 
}

FloatType& FloatType::divide( const DoubleType& dt ) 
{ 
    return divide( *dt.pointerToDoubleValue );   
}

FloatType& FloatType::add( const IntType& it )
{
    return add( *it.pointerToIntValue ) ;
}

FloatType& FloatType::subtract( const IntType& it ) 
{ 
    *pointerToFloatValue -= *it.pointerToIntValue;
    return subtract( *it.pointerToIntValue ); 
}

FloatType& FloatType::multiply( const IntType& it) 
{ 
    *pointerToFloatValue *= *it.pointerToIntValue;
    return multiply( *it.pointerToIntValue )  ; 
}

FloatType& FloatType::divide( const IntType& it ) 
{ 
    return divide( *it.pointerToIntValue );      
}

DoubleType& DoubleType::add( const FloatType& ft )
{
    return add( *ft.pointerToFloatValue ); 
}

DoubleType& DoubleType::subtract( const FloatType& ft ) 
{ 
    *pointerToDoubleValue -= *ft.pointerToFloatValue;
    return subtract( *ft.pointerToFloatValue ); 
}

DoubleType& DoubleType::multiply( const FloatType& ft ) 
{ 
    *pointerToDoubleValue *= *ft.pointerToFloatValue;
    return multiply ( *ft.pointerToFloatValue );
}

DoubleType& DoubleType::divide( const FloatType& ft ) 
{ 
    return divide( *ft.pointerToFloatValue );      
}

DoubleType& DoubleType::add( const IntType& it )
{
    return add( *it.pointerToIntValue );
}

DoubleType& DoubleType::subtract( const IntType& it ) 
{ 
    *pointerToDoubleValue -= *it.pointerToIntValue;
    return subtract( *it.pointerToIntValue ); 
}

DoubleType& DoubleType::multiply( const IntType& it ) 
{ 
    *pointerToDoubleValue *= *it.pointerToIntValue;
    return multiply( *it.pointerToIntValue ); 
}

DoubleType& DoubleType::divide( const IntType& it ) 
{ 
    return divide( *it.pointerToIntValue );      
}

IntType& IntType::add( const FloatType& ft )
{
    return add( *ft.pointerToFloatValue );
}

IntType& IntType::subtract( const FloatType& ft ) 
{ 
    return subtract( *ft.pointerToFloatValue );
}

IntType& IntType::multiply( const FloatType& ft ) 
{ 
    return multiply( *ft.pointerToFloatValue );
}

IntType& IntType::divide( const FloatType& ft ) 
{ 
    return divide( *ft.pointerToFloatValue );
}

IntType& IntType::add( const DoubleType& dt )
{
    return add( *dt.pointerToDoubleValue );
}

IntType& IntType::subtract( const DoubleType& dt ) 
{ 
    return add( *dt.pointerToDoubleValue ) ;
}

IntType& IntType::multiply ( const DoubleType& dt ) 
{ 
    return multiply( *dt.pointerToDoubleValue ); 
}

IntType& IntType::divide ( const DoubleType& dt ) 
{ 
    return divide( *dt.pointerToDoubleValue );
}


#include <iostream>

int main()
{   
    //testing instruction 0
    HeapA heapA ; 

    //assign heap primitives
    FloatType ft ( 0.137f );
    DoubleType dt (0.137 );
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

    std::cout << "\x1B[32m Chain calculation = " << *( (it.multiply(1000).divide(2).subtract(10).add(100)).pointerToIntValue ) << std::endl;

    std::cout << "good to go!" << std::endl;
}
