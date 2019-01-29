/***************************************************************************//**
 * @file
 ******************************************************************************/
#include "gas.h"

/***************************************************************************//**
 * @brief
 *    Constructor for this object
 *
 * @param[in] hp - The horsepower of this engine object
 ******************************************************************************/
Gas::Gas(int hp)
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
 *    Emit the noise made by this engine when it is revved
 ******************************************************************************/
void Gas::revEngine()
{
   cout << "Vrrroooom!\n";
}

/***************************************************************************//**
 * @brief
 *    Return an identifier which describes this derived type
 ******************************************************************************/
string Gas::type()
{
   return "Gas";
}

int main()
{
}
