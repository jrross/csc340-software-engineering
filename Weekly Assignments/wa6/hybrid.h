/***************************************************************************//**
 * @file
 ******************************************************************************/
#ifndef __HYBRID_H
#define __HYBRID_H

#include "engine.h"
/***************************************************************************//**
 * @class Hybrid
 * @brief
 *    A child class derived from the base class 'Engine'
 ******************************************************************************/
class Hybrid : public Engine
{
private:

public:
   /// Constructor
   Hybrid(int hp);

   /// Implementation of the base class virtual function
   void revEngine();
   /// Implementation of the base class virtual function
   string type();
};
#endif
