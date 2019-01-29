/***************************************************************************//**
 * @file
 ******************************************************************************/
#include "hybrid.h"

/***************************************************************************//**
 * @brief
 *    Constructor for this engine object
 *
 * @param[in] hp - the horsepower for this object
 ******************************************************************************/
Hybrid::Hybrid(int hp)
{
   if (hp < 1)
   {
      cerr << "Error, cannot create a diesel engine with " << hp << " horsepower\n";
      return;
   }
   horsePower = hp;
}

/***************************************************************************//**
 * @brief
 *    Emit the sound this engine makes when revved
 ******************************************************************************/
void Hybrid::revEngine()
{
   cout << "Buzzzzz\n";
}

/***************************************************************************//**
 * @brief
 *    Return an identifier which describes this derived object
 *
 * @return An identifier describing this object
 ******************************************************************************/
string Hybrid::type()
{
   return "Hybrid";
}
