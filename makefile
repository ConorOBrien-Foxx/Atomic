compile=g++
units=atomic.cpp noun.cpp data.cpp entity.cpp
out=atomic
options=-g -Wall -Werror=return-type
make:
	$(compile) -std=c++17 $(options) $(units) -o $(out)