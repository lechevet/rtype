CC	=	clang++

RM	=	rm -f

NAME	=	server

LINK	=	-ldl

SRC_DIR	=	src/

OBJ_DIR	=	obj/

FILES	=	main.cpp \
		Client.cpp \
		ClientManager.cpp \
		Lobby.cpp \
		LobbyManager.cpp \
		Server.cpp \
		Select.cpp \
		Game.cpp \
		AEntity.cpp \
		Ship.cpp \
		Vector.cpp \
		Enemy.cpp \
		DynamicLibrariesLoader.cpp \
		Weapon.cpp

DYNDIR	=	mods/

DYNCC	=	$(CC) -shared

DYNNAME	=	$(DYNDIR)Enemy.so

DYNOBJ	=	$(OBJ_DIR)Enemy.o

SRC	=	$(addprefix $(SRC_DIR), $(FILES))

OBJ	=	$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC	=	inc/

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
	$(CC) -c $< -o $@ -I $(INC) -g

$(NAME): init	 $(OBJ)
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

