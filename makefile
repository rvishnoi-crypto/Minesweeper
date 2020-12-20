CXX=gcc 
CXXFLAGS= -g -Wall # use -MMD to generate dependencies
SOURCES=$(wildcard *.c)   # list of all .cc files in the current directory
OBJECTS=${SOURCES:.c=.o}  # .o files depend upon .c files with same names
DEPENDS=${OBJECTS:.o=.d}   # .d file is list of dependencies for corresponding .c file
EXEC=minesweeper

# First target in the makefile is the default target.
# Note that the LIBFLAGS must come last in the command
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)

%.o: %.c 
	$(CXX) -c -o $@ $< $(CXXFLAGS) 

-include ${DEPENDS}

.PHONY: clean
clean:
	rm  -f $(OBJECTS) $(DEPENDS) $(EXEC)
