# Yahel Ben Ishay 305016297
# Sagi Shaashua 302915806

CXX = g++
#CXXFLAGS = -std=c++0x
RM = rm -f
#LIBS = -pthread -lboost_serialization -I.


Reversi.out: core.o makeO
	$(CXX) $(CXXFLAGS) @compile.txt exe

core.o:
	find src -name "*.cpp" > sources.txt
	$(CXX) $(CXXFLAGS) -c @sources.txt

makeO:
	find ./ -name "*.o" > compile.txt
clean:
	$(RM) *.o
	$(RM) sources.txt
	$(RM) compile.txt
