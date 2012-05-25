# interpolation.sh
#
# The shell script run ./exec/knot_get ./exec/fun_itp
# ./exec/interpolation sequencely, then call gnuplot on
# ./draw.gp to draw the graph.
# 
# With one argument for number of interpolation knots(num_itp),
# other arguments needed are set to:
# lower_bound = -1.0;
# upper_bound = 1.0;
# num_draw = 200;
#
#  Input:
#           Argument:
#             num_itp (number of interpolation knot, $1)
#  Output:
#           File:
#             result'$1'.png (result graph with $1 knots)
#
#Tuesday, March 27, 2012

#!/bin/sh
lower_bound=-1.0
upper_bound=1.0
num_draw=200
./exec/knot_get $lower_bound $upper_bound $1 $num_draw
./exec/fun_itp
./exec/interpolation
gnuplot ./draw.gp
mv ./graph/result.png ./graph/result_$1.png


