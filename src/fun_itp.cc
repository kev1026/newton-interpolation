// fun_itp.cc
// Generate the corresponding value on the knots provided by
// knot_draw knot_ipt
//
// Input:
//          Argument:
//          File:
//               ./data/knot_itp;./data/knot_draw
// Output:
//          ./data/fun_draw (points to show the original funciont)
//          ./data/value_itp (knots and corresponding value for interpolation)
//
// Sunday, March 11, 2012

#include <iostream>
#include <fstream>
#include <iomanip>

double fun_m(double x);

int main()
{
  using namespace std;
  ifstream fin;
  ofstream fout;

  // read knot_itp
  fin.open ("./data/knot_itp");
  fout.open ("./data/value_itp");

  double value;
  fin>>value;
  while (fin.good())
    {
      fout<<setw(15)<<value<<setw(15)<<fun_m(value)<<endl;
      fin>>value;
    }
  fin.close();
  fout.close();

  // read knot_draw
  fin.open ("./data/knot_draw");
  fout.open ("./data/fun_draw");
  fin>>value;
  while (fin.good())
    {
      fout<<setw(15)<<value<<setw(15)<<fun_m(value)<<endl;
      fin>>value;
    }
  fin.close();
  fout.close();

  return 0;
}

// this is the standard example to illustrate the Runge's phenomenon
double fun_m(double x)
{
  double y;
  y = 1 / (1 + 25 * x * x);

  return y;
}
