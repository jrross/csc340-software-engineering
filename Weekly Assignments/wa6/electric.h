/***************************************************************************//**
 * @file
 ******************************************************************************/
#ifndef __ELECTRIC_H
#define __ELECTRIC_H

#include "engine.h"

/***************************************************************************//**
 * @class Electric
 * @brief
 *    A child class derived from the base class 'Engine'
 ******************************************************************************/
class Electric : public Engine
{
private:

public:
   /// Constructor
   Electric(int hp);

   /// Implementation of the base class virtual function by the same name
   void revEngine();
   /// Implementation of the base class virtual function by the same name
   string type();
};
#endif
