/***************************************************************************//**
 * @file
 ******************************************************************************/
#include "electric.h"

/**************************************************************************//**
 * @brief
 *   The constructor for the derived 'electric' class
 *
 * @param[in] hp - create an electric engine object that has 'hp' horsepower
 ******************************************************************************/
Electric::Electric(int hp)
{
   if (hp < 1)
   {
      cerr << "Error, cannot create a electric engine with " << hp << " horsepower\n";
      return;
   }
   horsePower = hp;
}

/**************************************************************************//**
 * @brief
 *    Implementation of the abstract base class member function which emits
 *    the sound the engine (or in this case, motor) makes when it is revved
 *****************************************************************************/
void Electric::revEngine()
{
   cout << "Hummmmm\n";
}

/**************************************************************************//**
 * @brief
 *    Implementation of the virtual identifier attribute for the base class.
 *    The base class 'type' is virtual so this must have an implemenation.
 *****************************************************************************/
string Electric::type()
{
   return "Electric";
}
