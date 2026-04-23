CXXFLAGS	= -O0 -pedantic
CXXC		= g++
RM			= rm
#--------------------------------------------------------------------------------

vinho: main.o util.o ABB.o	
	$(CXXC) main.o util.o ABB.o -o vinho

main.o: main.cpp ABB.hpp util.hpp estrutura.hpp
	$(CXXC) $(CXXFLAGS) -c main.cpp

ABB.o: ABB.cpp ABB.hpp estrutura.hpp
	$(CXXC) $(CXXFLAGS) -c ABB.cpp

util.o: util.cpp 
	$(CXXC) $(CXXFLAGS) -c util.cpp

clean:
	$(RM) *.o vinho