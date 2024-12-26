.PHONY: all run clean echo

SRC = $(shell find . -iname "*.c")
OBJ = $(patsubst %.c, %.o, $(SRC))
TARGET = build/bin

run: all
	@./build/bin

all: $(TARGET)

# linking stage
# picks all the object files and produce the binary output (TARGET)
$(TARGET): $(OBJ)
	@$(CXX) -o $@ $^

# compile stage
# picks all the source files and produces the object files
# this is necessary for the makefiles to know how to handle .o files
%.o: %.c
	@$(CXX) -std=c++20 -o $@ -c $^

clean:
	rm **/*.o
	rm build/bin
