#-------------------------------------------------------------------------------#
#                                THUG MAKEFILE                                  #
#-------------------------------------------------------------------------------#

# Debug false will build in release mode
DEBUG	=	true

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
			engine/utils/resources.cpp											\
			game/box.cpp														\
			game/sphere.cpp														\
			game/game.cpp

DIRS	=	bin\engine\maths													\
			bin\engine\graphics													\
			bin\engine\inputs													\
			bin\engine\utils													\
			bin\engine\physics													\
			bin\game

NAME = THUG
LDFLAGS =	-lBulletSoftBody -lBulletDynamics -lBulletCollision		 			\
			-lLinearMath

ifeq ($(OS),Windows_NT)
	GLFLAGS = 	--static -lglfw3 -lglew32 -lopengl32 -lgdi32
	LIB = ./libs/win/
	NAME := $(NAME).exe
	MKDIR = mkdir
	RMDIR = rmdir /s /q
	RM = del
	EXEC = $(NAME)
	SYSTEM = Windows
else
	SYSTEM = $(shell uname -s)
	ifeq (SYSTEM,Darwin)
	else
		GLFLAGS = 	-lglfw3 -lGL -lm -lGLU -lGLEW -lXrandr -lXi -lX11 -lXxf86vm \
					-lpthread -ldl -lXinerama -lXcursor -lrt
		LIB = ./libs/linux/
		NAME := $(NAME)
		MKDIR = mkdir -p
		RMDIR = rm -rf
		RM = rm -rf
		EXEC = ./$(NAME)
	endif
endif

CXX = g++

ifeq ($(DEBUG),true)
	CXXFLAGS = 	-I ./includes/													\
				-I ./includes/Bullet/ 											\
				-std=c++11 -Wall -Wextra -g										\
				-L $(LIB) $(GLFLAGS) $(LDFLAGS)
else
	CXXFLAGS = 	-I ./includes/													\
				-I ./includes/Bullet/ 											\
				-std=c++11 -Wall -Wextra										\
				-L $(LIB) $(GLFLAGS) $(LDFLAGS)
endif

BIN = bin
SRC = $(addprefix src/,$(FILES))
OBJ = $(addprefix $(BIN)/,$(FILES:.cpp=.o))

all: $(DIRS) $(NAME)
	@echo "\n----------------- Build complete -----------------"
	@echo "System: $(SYSTEM)"
	@echo "Debug mode: $(DEBUG)"

$(DIRS):
	$(MKDIR) $(DIRS)

$(NAME): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(BIN)/%.o: src/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean fclean re test

clean:
	$(RMDIR) $(BIN)

fclean: clean
	$(RM) $(NAME)

re: clean all

test : all
	$(EXEC)
