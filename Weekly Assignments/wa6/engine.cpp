/***************************************************************************//**
 * @file
 ******************************************************************************/
#include "engine.h"

/***************************************************************************//**
 * @brief
 *    Accessor which returns the value of the horsepower of this object
 ******************************************************************************/
int Engine::getHorsePower() const
{
   return horsePower;
}

/***************************************************************************//**
 * @brief
 *   Mutator which allows the horsepower for this object to be set.
 *
 * @param[in] hp - the new value of horsepower to assign this object
 ******************************************************************************/
void Engine::setHorsePower(int hp)
{
   if (hp < 1)
   {
      cerr << "Error, cannot create engine with " << hp << " horsepower\n";
      return;
   }
   horsePower = hp;
}
