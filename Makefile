#-------------------------------------------------------------------------------#
#                                THUG MAKEFILE                                  #
#-------------------------------------------------------------------------------#

# We have to do this because of Winshit and because wildcards are bad
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
			engine/inputs/input.cpp												\
			engine/utils/timer.cpp												\
			engine/physics/physics_world.cpp									\
			engine/graphics/mesh.cpp											\
			engine/graphics/obj_loader.cpp										\
			game/box.cpp														\
			game/game.cpp

# We also have to do this because of Winshit but predominately because of Winshit 
DIRS	=	bin\engine\maths													\
			bin\engine\graphics													\
			bin\engine\inputs													\
			bin\engine\utils													\
			bin\engine\physics													\
			bin\game

LDFLAGS = 	--static -lglfw3 -lglew32 -lopengl32 -lgdi32 						\
			-lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath	\
			-lfreetype

NAME = THUG
CXX = g++
CXXFLAGS = -I ./includes/ -I ./includes/Bullet/ -I ./includes/FreeType/ -std=c++11 -L ./libs/ $(LDFLAGS)
BIN = bin
SRC = $(addprefix src/,$(FILES))
OBJ = $(addprefix $(BIN)/,$(FILES:.cpp=.o))

all: $(DIRS) $(NAME)

$(DIRS):
	mkdir $(DIRS)

$(NAME): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(BIN)/%.o: src/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean fclean

clean:
	rmdir /s /q $(BIN)

fclean: clean
	del $(NAME).exe

test : all
	$(NAME).exe
