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
//struct DoubleType;
//struct IntType;

struct FloatType
{
private:
    float* pointerToFloatValue = nullptr;

public:
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

    operator float() { return *pointerToFloatValue; }

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
private:
    double* pointerToDoubleValue = nullptr;

public:
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

    operator double() { return *pointerToDoubleValue; }
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
private:
    int* pointerToIntValue = nullptr;
   
public:
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
    
    operator int() { return *pointerToIntValue; }
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

#include <iostream>

int main()
{   

    //assign heap primitives
    FloatType ft ( 10 );
    DoubleType dt ( 10 );
    IntType it ( 10 ) ;

    std::cout << "FloatType add result=" <<  ft.add( 2 )  << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f )  << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ) << std::endl;
    std::cout << "FloatType divide result=" <<  ft.divide( 16.0f) << std::endl << std::endl;

    std::cout << "DoubleType add result=" << dt.add(2.0) << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0) << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(static_cast<double>(2.5f)) << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(0) << std::endl << std::endl;

    std::cout << "IntType add result=" << it.add(static_cast<int>(2.25f)) << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2) << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2) << std::endl;
    std::cout << "IntType divide result=" << it.divide(0) << std::endl << std::endl;

    //my example of a rounding loss causing an int divide by zero in the chain
    std::cout << "\x1B[32m Chain calculation = " << ( it.multiply(1000).divide(static_cast<int>(0.125f)).subtract(10).add(100) ) << std::endl;

    std::cout << "good to go!" << std::endl;
}
