CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++11

SRC = 01_uniq.cc            \
      02_getters.cc           \
      03_converter.cc                \
      04_text_formatter.cc
EXE = $(SRC:.cc=.x)

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cc .x

all: $(EXE)

.PHONY: all

%.x: %.cc 
	$(CXX) $< -o $@ $(CXXFLAGS)

format: $(SRC)
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this command"

.PHONY: format

clean:
	rm -f $(EXE) *~

.PHONY: clean
