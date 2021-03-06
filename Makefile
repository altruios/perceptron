OBJS=main.o Perceptron.o Cortex.o

EXE=perceptron
LDFLAGS_BASE=-Lexternal/lib -lsfml-system -lsfml-window -lsfml-graphics 
CXXFLAGS_BASE=-std=c++17 -Iexternal/include -Iinclude -DSFML_STATIC -c 

all: $(EXE) 

opt:
	$(MAKE) -B CXXFLAGS=-O3

$(EXE): $(OBJS)
	g++ $^ -o $@ $(LDFLAGS_BASE) $(LDFLAGS)

%.o: library/%.cpp
	g++ $^ -o $@ $(CXXFLAGS_BASE) $(CXXFLAGS)
