SRC = 01_matrixtranspose.cpp \
 02_convertargvtotypes.cpp \
 03_meanandmedian.cpp \
 04_avoidrepeatedwords.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++14

EXE = $(SRC:.cpp=.x)

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cpp .x

all: $(EXE)

.PHONY: all

%.x: %.cpp 
	$(CXX) $< -o $@ $(CXXFLAGS)

format: $(SRC)
	@clang-format -i $^ -verbose || echo "Please install clang-format to run this command"

.PHONY: format

clean:
	rm -f $(EXE) *~

.PHONY: clean

01_const_and_pointers.x : CXXFLAGS += -Wno-unused-variable -Wno-unused-but-set-variable
02_special_pointers.x : CXXFLAGS += -Wno-unused-variable -Wno-unused-but-set-variable -Wno-uninitialized
