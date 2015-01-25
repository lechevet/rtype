CC	=	clang++

RM	=	rm -f

NAME	=	client

LINK	=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -ldl -g

SRC_DIR	=	src/

OBJ_DIR	=	obj/

FILES	=	main.cpp \
		SpriteGiver.cpp \
		Client.cpp \
		AudioManager.cpp

# DYNDIR	=	mods/

# DYNCC	=	$(CC) -shared

# DYNNAME	=	$(DYNDIR)Enemy.so

# DYNOBJ	=	$(OBJ_DIR)Enemy.o
SRC	=	$(addprefix $(SRC_DIR), $(FILES))

OBJ	=	$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC	=	inc/

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
	$(CC) -c $< -o $@ -I $(INC) -g

$(NAME):  $(OBJ)
	$(CC) -rdynamic -o $(NAME) $(OBJ) -I $(INC) $(LINK)
##	$(DYNCC) -o $(DYNNAME) $(DYNOBJ)

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

