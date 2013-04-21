BUILD_DIR := obj

CPP := g++
LD := g++

CFLAGS :=
LDFLAGS := 
TFLAGS := -DRUN_TESTS

SRC_DIR := ../../proj2

CPP_SRC := $(wildcard $(SRC_DIR)/*.cpp)
CPP_OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CPP_SRC))
TEST_CPP_OBJS := $(patsubst $(TFLAGS) $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CPP_SRC))

all : project

project : build_dir $(CPP_OBJS)
	$(LD) -o $@ $(CPP_OBJS) $(LDFLAGS)

tests : build_dir $(CPP_OBJS)
	$(LD) $(TFLAGS) -o $@ $(TEST_CPP_OBJS) $(LDFLAGS)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<

build_dir :
	mkdir -p $(BUILD_DIR)

clean :
	rm -rf $(BUILD_DIR)
	rm -f project
	rm -f tests

rebuild : clean all

test : project
