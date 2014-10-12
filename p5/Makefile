srcdir=src
bindir=bin
objdir=obj
exec=list

full_exec = $(bindir)/$(exec)

VPATH = $(srcdir) $(bindir) $(objdir) 
CXX=g++
CXXFLAGS=-O2 -Wall -pedantic -Wextra


objects=$(patsubst $(srcdir)/%.cpp, %.o,$(wildcard $(addsuffix /*.cpp, $(srcdir))))

all: $(bindir) $(objdir) $(exec)

$(bindir): 
	mkdir -p $(bindir)
$(objdir):
	mkdir -p $(objdir)

-include Makefile.dep
Makefile.dep: $(srcdir)/*.cc
	$(CXX) $(CXXFLAGS) -MM  $(srcdir)/*.cc | sed -e 's/^\(\S.*\)/\1/' > $@

$(exec): $(objects) 
	$(CXX) $(CXXFLAGS) $(addprefix $(objdir)/, $(objects)) -o $(bindir)/$@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $(objdir)/$@	

test: all 
	$(full_exec) ab.pp

.PHONY: clean

clean:
	rm -rf bin/
	rm -rf obj/
	rm -rf Makefile.dep
