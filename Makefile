C++ = g++
CFLAGS = -c -g

all: centerDriver Ml_hash

centerDriver:	centerDriver.o Vehicle.o Cars.o Motorcycle.o Hybrid.o Buses.o Task.o ML_hash.o
		$(C++) -o FinalProjectPt2 centerDriver.o Vehicle.o Cars.o Motorcycle.o Hybrid.o Buses.o Task.o ML_hash.o

Ml_hash:	ML_hash.o benchMark.o random_op.o
		$(C++) -o FinalProjectPt1 benchMark.o  ML_hash.o random_op.o
		
clean:
		rm -f *.o

%.o:	%.cpp
		$(C++) $(CFLAGS) $*.cpp

