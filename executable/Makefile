
project_name=executable
exec_name=$(project_name)
source=$(project_name).cpp
CXX_FLAGS=-DLIB_INTERFACE_PATH=\"${PWD}/interface/libinterface.dylib\"
LD_FLAGS=-undefined dynamic_lookup -L ../backend -L ../interface
LD_LIBRARIES=-l interface -l backend
INC=-I ..

all:$(exec_name)

$(exec_name):$(source)
	g++ $< -o $@ $(INC) $(CXX_FLAGS) $(LD_FLAGS) $(LD_LIBRARIES)

clean:
	rm -f $(exec_name)

