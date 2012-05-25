VPATH=./exec:./src:.

all : knot_get fun_itp interpolation clean
.PHONY : all

knot_get : knot_get.cc
	g++ -o ./exec/$@ $<
fun_itp : fun_itp.cc
	g++ -o ./exec/$@ $<
interpolation : main_m.o main_fun_def.o
	g++  $^ -o ./exec/$@ 
main_m.o : main_m.cc main_head.h
	g++ -c  $< -o $@ 
main_fun_def.o : main_fun_def.cc main_head.h
	g++ -c  $< -o $@

.PHONY: clean
clean :
	-rm -f *.o