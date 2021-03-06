BINDIR= bin
SRCDIR= src

CXX= g++
RM= rm

EXEC= $(BINDIR)/cpp_test.exe
OBJS= $(SRCDIR)/main.o

#CAN NOT write: OBJS= $(SRCDIR)/main.o $(SRCDIR)/tstack.o 
#because tstack is a class template, should not be compile to a specific obj before used/instantiate. 
#if has to be able to read again when the compiler meet the instantiation of the class template.
#the effect now is the same as define all the interface in tstack.h rather than in a seperate tstack.cpp

CXXFLAGS+= -I./h
LIBDIR=
LDFLAGS+= $(LIBDIR)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

.PHONY: clean
clean:
	$(RM) -f $(EXEC) $(SRCDIR)/*.o
