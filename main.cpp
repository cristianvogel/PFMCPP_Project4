/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

 Create a branch named Part3
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type
 
 2) remove any getValue() functions if you added them
 
 3) move all of your add/subtract/multiply/divide implementations out of the class.
  
 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
 
 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
 
 6) clean up any forward declaration that you might have.
 
 7) make sure it compiles & runs without errors.
 
 8) use your knowledge of casting to remove any conversion warnings. 
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

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
    std::string warning = (abs(y) > 0) ? "" : "\x1B[31m Divide-by-zero warning! \x1B[0m";
    std::cout << warning << std::endl;   

    *pointerToFloatValue /= y; 
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
    std::string warning = (abs(y) > 0) ? "" : "\x1B[31m Divide-by-zero warning! \x1B[0m";
    std::cout << warning << std::endl;
    *pointerToDoubleValue /= y;    
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
        std::cout << "\x1B[31m Cannot divide Int by Zero! \x1B[0m" << std::endl;
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
    return subtract( *it.pointerToIntValue ); 
}

FloatType& FloatType::multiply( const IntType& it) 
{ 
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
    return subtract( *ft.pointerToFloatValue ); 
}

DoubleType& DoubleType::multiply( const FloatType& ft ) 
{ 
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
    return subtract( *it.pointerToIntValue ); 
}

DoubleType& DoubleType::multiply( const IntType& it ) 
{ 
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
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << *( ft.add( 2.0f ).pointerToFloatValue ) << std::endl;
    std::cout << "FloatType subtract result=" << *( ft.subtract( 2.0f ).pointerToFloatValue ) << std::endl;
    std::cout << "FloatType multiply result=" << *( ft.multiply( 2.0f ).pointerToFloatValue ) << std::endl;
    std::cout << "FloatType divide result=" << *( ft.divide( 16.0f).pointerToFloatValue ) << std::endl << std::endl;

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
