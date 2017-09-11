CXX = g++
# Using C++11
CXX_FLAGS = -Wall -O3 -std=c++0x
CXX_DFLAGS = -DDEBUG
# Libraries to link against
LIBS = -lSDL2 -lSDL2_image -lGL -lGLU

SRC_DIR = src
OBJ_DIR = objs

EXEC = renderer.out
DEXEC = renderer_debug.out

# Get all the source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# Get all the object files
OBJECTS = $(wildcard $(OBJ_DIR)/*.o)

all:
	\mkdir -p objs
	$(CXX) $(CXX_FLAGS) -c $(SOURCES) $(LIBS)
	\mv -f *.o $(OBJ_DIR)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) -o $(EXEC) $(LIBS)

debug:
	\mkdir -p objs
	$(CXX) $(CXX_FLAGS) $(CXX_DFLAGS) -c $(SOURCES) $(LIBS)
	\mv -f *.o $(OBJ_DIR)
	$(CXX) $(CXX_FLAGS) $(CXX_DFLAGS) $(OBJECTS) -o $(DEXEC) $(LIBS)

clean:
	\rm $(OBJ_DIR)/*
	\rm renderer
