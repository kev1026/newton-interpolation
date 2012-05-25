// main_m.cc
// generate the interpolation function and output the value
// of the function corresponding to knots in knot_draw
// the maximum number of  interpolaton knots(degree) set to 50
//
// Input:
//          File:
//              ./data/value_itp
//              ./data/knot_draw
// Output:
//          File:
//              ./data/fun_itp_draw
//
// Sunday, March 11, 2012

#include <iostream>
#include <fstream>
#include <iomanip>
#include "main_head.h"
int main()
{
  using namespace std;
  const int max_degree_m=50;
  int degree_m=0;		// this state the number of
				// interpolation knots
  double coef[max_degree_m];
  double knot_itp[max_degree_m];

  // read from ./data/value_itp, knots for interpolation and
  // corresponding value on those knots
  ifstream fin;
  double value;
  fin.open("./data/value_itp");
  fin>>value;
  knot_itp[0]=value;
  fin>>value;
  coef[0]=value;
  
  while (fin.good())
    {
      degree_m++;
      fin>>value;
      knot_itp[degree_m]=value;
      fin>>value;
      coef[degree_m]=value;
    }
  fin.close();

  // TEST: Show the input result
  for (int i=0; i<degree_m; i++)
    {
      cout<<setw(15)<<knot_itp[i]<<setw(15)<<coef[i]<<endl;
    }
  
  // calculate the coeffidents of Newton's style
  // still saved in coef
  ItpCoef_m(coef, knot_itp, degree_m);
  // TEST: Show the result to screen
  for (int i=0; i<degree_m; i++)
    {
      cout<<setw(15)<<knot_itp[i]<<setw(15)<<coef[i]<<endl;
    }
 
  // form the interpolation function and output the value on
  // knots in knot_draw to file fun_itp_draw
  ItpFunc_m(coef, knot_itp, degree_m);

  return 0;
}

