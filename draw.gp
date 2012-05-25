# draw.gp
#
# Script file for gnuplot, draw the result.
#
# Input:
#	File:
#		./data/fun_draw
#		./data/fun_itp_draw
#		./data/value_itp
# Output:
#	File:
#		./graph/result.png
#
#Tuesday, March 27, 2012

set terminal png
set output "./graph/result.png"

set key off
set style line 1 lt -1 lw 1
set style line 2 lt 0 lw 2

plot [][] "./data/fun_draw" t "function" w line ls 1, "./data/fun_itp_draw" t "interpolation function" w line ls 2, "./data/value_itp" t "interpolation knots" w points ls 20
