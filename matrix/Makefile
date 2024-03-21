

CXXFLAGS = -std=c++11

objects = Test.o symmetricMatrix.o

Test:$(objects)
	g++ $(objects) -o Test
$(objects):%.o:%.cpp
	g++ -c $< -o $@ $(CXXFLAGS)





#Test:Test.o 
#	g++ Test.o -o Test
#Test.o:Test.s
#	g++ -c Test.s -o Test.o
#Test.s:Test.i
#	g++ -S Test.i -o Test.s
#Test.i:Test.cpp
#	g++ -E Test.cpp -o Test.i


.PHONY:clean
clean:
	rm *.o  Test
