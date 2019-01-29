/***************************************************************************//**
 * @file
 ******************************************************************************/
#ifndef __DIESEL_H
#define __DIESEL_H

#include "engine.h"

/***************************************************************************//**
 * @class Diesel
 * @brief
 *    A child class derived from the baseclass 'Engine'
 *
 ******************************************************************************/
class Diesel : public Engine
{
private:

public:
   /// Constructor
   Diesel(int hp);

   /// Implementation of the base class virtual function
   void revEngine();
   /// Implementation of the base class virtual function
   string type();
};
#endif
