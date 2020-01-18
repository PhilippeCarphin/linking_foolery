
project_name=interface
library_name=lib$(project_name).dylib
source=$(project_name).cpp
LD_FLAGS=-dynamiclib -undefined dynamic_lookup -L ../backend
LD_LIBRARIES=-l backend
INC=-I ..

all:$(library_name)


$(library_name):$(source)
	g++ $< -o $@ $(INC) $(LD_FLAGS) $(LD_LIBRARIES)

clean:
	rm -f $(library_name)
