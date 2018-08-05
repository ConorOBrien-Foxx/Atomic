compile=g++
units=atomic.cpp noun.cpp data.cpp entity.cpp
out=atomic
options=-g -Wall -Werror=return-type
make:
	$(compile) $(options) $(units) -o $(out)