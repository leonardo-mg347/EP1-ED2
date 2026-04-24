CXXFLAGS	= -O0 -pedantic
CXXC		= g++
RM			= rm
#--------------------------------------------------------------------------------

vinho: main.o util.o ABB.o	RBTree.o
	$(CXXC) main.o util.o ABB.o RBTree.o -o vinho

main.o: main.cpp ABB.hpp util.hpp estrutura.hpp
	$(CXXC) $(CXXFLAGS) -c main.cpp

ABB.o: ABB.cpp ABB.hpp estrutura.hpp
	$(CXXC) $(CXXFLAGS) -c ABB.cpp

RBTree.o: RBTree.cpp RBTree.hpp estrutura.hpp
	$(CXXC) $(CXXFLAGS) -c RBTree.cpp

util.o: util.cpp 
	$(CXXC) $(CXXFLAGS) -c util.cpp

clean:
	$(RM) *.o vinho