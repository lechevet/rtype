CC	=	clang++

RM	=	rm -f

NAME	=	server

LINK	=	-ldl -lpthread -g

SRC_DIR	=	src/

OBJ_DIR	=	obj/

FILES	=	main.cpp \
		Client.cpp \
		Server.cpp \
		ClientManager.cpp \
		game/Ship.cpp \
		game/AEntity.cpp \
		game/Vector.cpp \
		game/Game.cpp \
		game/Enemy.cpp \
		game/DynamicLibrariesLoader.cpp \
		game/Starfield.cpp \
		game/Weapon.cpp

DYNDIR	=	mods/

DYNCC	=	$(CC) -shared

DYNNAME	=	$(DYNDIR)Enemy.so

DYNOBJ	=	$(OBJ_DIR)game/Enemy.o

SRC	=	$(addprefix $(SRC_DIR), $(FILES))

OBJ	=	$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC	=	inc/

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
	$(CC) -c $< -o $@ -I $(INC) -g

$(NAME): $(OBJ)
	$(CC) -rdynamic -o $(NAME) $(OBJ) -I $(INC) $(LINK)
	$(DYNCC) -o $(DYNNAME) $(DYNOBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME) $(DYNNAME)

re: fclean all

init:
	@mkdir -p inc
	@mkdir -p src
	@mkdir -p obj
	@mkdir -p mods

.PHONY: all clean fclean re

