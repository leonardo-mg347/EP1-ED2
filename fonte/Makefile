CXXFLAGS	= -O0 -pedantic
CXXC		= g++
RM			= rm
#--------------------------------------------------------------------------------

vinho: main.o util.o ABB.o	RBTree.o Treap.o Splay.o
	$(CXXC) main.o util.o ABB.o RBTree.o Treap.o Splay.o -o vinho

main.o: main.cpp util.hpp estrutura.hpp
	$(CXXC) $(CXXFLAGS) -c main.cpp

ABB.o: ABB.cpp ABB.hpp estrutura.hpp
	$(CXXC) $(CXXFLAGS) -c ABB.cpp

RBTree.o: RBTree.cpp RBTree.hpp estrutura.hpp
	$(CXXC) $(CXXFLAGS) -c RBTree.cpp

Treap.o: treap.cpp treap.hpp estrutura.hpp
	$(CXXC) $(CXXFLAGS) -c treap.cpp

Splay.o: splay.cpp splay.hpp estrutura.hpp
	$(CXXC) $(CXXFLAGS) -c splay.cpp

util.o: util.cpp 
	$(CXXC) $(CXXFLAGS) -c util.cpp

clean:
	$(RM) *.o vinho