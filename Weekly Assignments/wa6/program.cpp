/***************************************************************************//**
 * @file
 *
 * @mainpage Inheritance example
 *
 * @author Dr. Paul Hinker
 *
 * @date Jan. 17, 2016
 *
 * @par Course:
 *      CSC 300 - Data Structures - 10:00am MWThF
 *
 * @par Location:
 *      McLaury Building, Room 205
 *
 * @par Description:
 *      Concepts demonstrated
 *
 *      * Simple inheritance
 *      * Late binding
 *      * Abstract Base Class
 *      * Member function overriding
 ******************************************************************************/

#include <iostream>
#include <vector>
#include "engine.h"
#include "electric.h"
#include "hybrid.h"
#include "gas.h"
#include "diesel.h"

using namespace std;

/**************************************************************************//**
 * @par Description:
 *      Demonstrates late binding by calling the over ridden base class member 
 *      functions 'type' and 'revEngine'.
 *
 * @param[in] e - Pointer to abstract base class
 ******************************************************************************/
void startYourEngine(Engine *e)
{
   cout << e->type() << " ";
   e->revEngine();
}

/***************************************************************************//**
 * @par Description:
 *      Simple driver
 *
 * @returns 0 on exit
 ******************************************************************************/
int main()
{
   vector<Engine*> engines;

   engines.push_back(new Electric(10));
   engines.push_back(new Hybrid(100));
   engines.push_back(new Gas(343));
   engines.push_back(new Diesel(523));

   for (auto x : engines)
      startYourEngine(x);

   return 0;
}
