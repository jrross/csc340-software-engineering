/***************************************************************************//**
 * @file
 ******************************************************************************/

#ifndef __ENGINE_H
#define __ENGINE_H

#include <iostream>
using namespace std;
/**************************************************************************//**
 * @file
 *****************************************************************************/
class Engine
{
protected:
   /// A description of the power output of the engine
   int horsePower;

public:
   /// Virtual function makes the base class abstract
   virtual void revEngine() = 0;
   
   // Accessor
   /// Return value of the horse power value
   int getHorsePower() const;

   /// Virtual function that derived classes must implement
   virtual string type() = 0;

   // Mutator
   /// Modify the horse power value
   void setHorsePower(int hp);
};

#endif
