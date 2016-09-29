FILES	=	main.cpp															\
			engine/graphics/display.cpp											\
			engine/maths/vec3.cpp												\
			engine/maths/mat4.cpp												\
			engine/maths/quat.cpp												\
			engine/graphics/shader.cpp											\
			engine/utils/error.cpp												\
			engine/utils/string_utils.cpp										\
			engine/utils/file_utils.cpp											\
			engine/maths/transform.cpp											\
			engine/graphics/camera.cpp											\
			game/game.cpp

NAME = THUG
CXX = g++
LDFLAGS = -lglfw3 -lglew32 -lopengl32 -lgdi32
CXXFLAGS = -I includes/ -std=c++11 -L libs/ $(LDFLAGS)
SRC = $(addprefix src/,$(FILES))
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

THUG: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean fclean

clean:
	del $(OBJ)

fclean: clean
	del $(NAME)

test : all
	THUG.exe
