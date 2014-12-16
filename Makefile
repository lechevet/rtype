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
		Enemy.cpp \
		BasicWeapon.cpp \
		SpriteGiver.cpp \
		Starfield.cpp

SRC	=	$(addprefix $(SRC_DIR), $(FILES))

OBJ	=	$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC	=	inc/

LINK	=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -g

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
	$(CC) -c $< -o $@ -I $(INC)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LINK) -I $(INC)

all:	$(NAME)
clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

