CC	=	clang++

RM	=	rm -f

NAME	=	rtype

SRC_DIR	=	src/

OBJ_DIR	=	obj/

FILES	=	main.cpp \
		EntityManager.cpp \
		EventManager.cpp \
		AEntity.cpp \
		Ship.cpp \
		AudioManager.cpp \
		AWeapon.cpp \
		BasicWeapon.cpp \
		SpriteGiver.cpp \
		Starfield.cpp \
		DynamicLibrariesLoader.cpp \
		Enemy.cpp

DYNDIR	=	mods/

DYNCC	=	$(CC) -shared

DYNNAME	=	$(DYNDIR)Enemy.so

DYNOBJ	=	$(OBJ_DIR)Enemy.o

SRC	=	$(addprefix $(SRC_DIR), $(FILES))

OBJ	=	$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC	=	inc/

LINK	=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -ldl -g

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
	$(CC) -c $< -o $@ -I $(INC)

$(NAME):	 $(OBJ)
	$(CC) -rdynamic -o $(NAME) $(OBJ) $(LINK) -I $(INC)
	$(DYNCC) -o $(DYNNAME) $(DYNOBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME) $(DYNNAME)

re: fclean all

.PHONY: all clean fclean re

