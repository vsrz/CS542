BUILD_DIR := bin
PROJ := proj2

CPP := g++
LD := g++

CFLAGS :=
LDFLAGS := 

SRC_DIR := ../../$(PROJ)

CPP_SRC := $(wildcard $(SRC_DIR)/*.cpp)

all : project

project :
	$(CPP) -o $(PROJ) $(CPP_SRC) $(LDFLAGS)

$(BUILD_DIR)/%.o : $(OMEGA_SRC_DIR)/%.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<

build_dir :
	mkdir -p $(BUILD_DIR)

clean :
	rm -rf $(BUILD_DIR)
	rm -f $(PROJ)

rebuild : clean all

test : $(PROJ)

