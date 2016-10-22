C := g++
HDIR := include
SDIR := src
TDIR := test
ODIR := out

CFLAGS := -I./$(HDIR)
SRC := $(SDIR)/vector.cpp
TEST := $(TDIR)/test.cpp
OBJ := $(ODIR)/test.o $(ODIR)/vector.o

createobj = $(C) -c -o $(ODIR)/$(1) $(2) $(CFLAGS)
createout = $(C) -o $(ODIR)/$(1) $(2) $(CFLAGS)

all: vector

vector: test.o vector.o
	$(call createout,$@,$(OBJ))
vector.o: $(SRC)
	$(call createobj,$@,$^)
test.o: $(TEST)
	$(call createobj,$@,$^)

clean:
	rm -r $(ODIR)/*
