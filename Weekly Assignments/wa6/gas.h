/***************************************************************************//**
 * @file
 ******************************************************************************/

#ifndef __GAS_H
#define __GAS_H

#include "engine.h"

/***************************************************************************//**
 * @class Gas
 * @brief
 *    A child class derived from the base class 'Engine'
 ******************************************************************************/
class Gas : public Engine
{
private:

public:
   /// Constructor
   Gas(int hp);

   /// Implementation of the base class virtual function
   void revEngine();

   /// Implementation of the base class virtual function
   string type();
};
#endif
