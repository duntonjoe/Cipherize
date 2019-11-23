.PHONY: clean

SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
DEP := $(SRC:.cpp=.d)

CPPFLAGS := -MMD

cipherize: $(OBJ)
	$(LINK.cpp) $^ -o $@

clean:	
	rm *.o cipherize

-include $(DEP)
