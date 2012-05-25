// main_fun_def.cc
// definition of the function used in main file


#include <fstream>
#include <iomanip>
#include <iostream>
#include "main_head.h"

void ItpCoef_m(double *itp_coef, double *knot_itp, int degree_m)
{
  for (int i=0; i<degree_m-1; i++)
    for (int k=degree_m-1; k>i; k--)
      {
	itp_coef[k] = (itp_coef[k-1]-itp_coef[k])/(knot_itp[k-i-1]-knot_itp[k]);
      }
}

void ItpFunc_m(double *itp_coef, double *knot_itp, int degree_m)
{
  using namespace std;
  double value,x;
  ifstream fin;
  ofstream fout;

  fin.open("./data/knot_draw");
  fout.open("./data/fun_itp_draw");
  fin>>x;
  while(fin.good())
    {
      value = itp_coef[degree_m-1];
      fout<<setw(15)<<x;
      for (int i=degree_m-1; i>0; i--)
	{
	  value = itp_coef[i-1]+(x-knot_itp[i-1])*value;
	}
      fout<<setw(15)<<value<<endl;
      fin>>x;
    }

  fin.close();
  fout.close();
}
