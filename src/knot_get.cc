// knot_get.cc
// Generate the plot knots for interpolation and drawing.
//
// Input:
//         Argument:
//           lower_bound; upper_bound; num_itp ; num_draw
//           
//         File:
// Output:
//         File:
//         ./data/knot_itp (knot for interpolation)
//         ./data/knot_draw (knot for drawing)
//
// Sunday, March 11, 2012
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  using namespace std;
  if (argc != 5)		// Quit if argument is wrong
    {
      cerr<<"Usage:"<<argv[0]<<" lower_bound upper_bound num_itp num_draw "<<endl;
      exit(EXIT_FAILURE);
    }
  double low_bnd=atof(argv[1]);
  double upp_bnd=atof(argv[2]);
  double num_itp=atof(argv[3]);
  double num_draw=atof(argv[4]);

  ofstream fout;
  double itv_len;		// length of the intervals
  
  itv_len = (upp_bnd-low_bnd)/num_itp;
  fout.open("./data/knot_itp");		// first generate knot_itp
  for (float x=low_bnd; x<=upp_bnd; x+=itv_len)
    fout<<x<<endl;
  fout.close();

  itv_len = (upp_bnd-low_bnd)/num_draw;
  fout.open("./data/knot_draw");
  for (float x=low_bnd; x<=upp_bnd; x+=itv_len)
    fout<<x<<endl;
  fout.close();

  return 0;
}
