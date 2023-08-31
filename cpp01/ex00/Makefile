# ╔════════════════════════════════════════════════════════════════════════╗
# ║                       Makefile for C++ exercises                       ║
# ╚════════════════════════════════════════════════════════════════════════╝
# ╭────────────────────────────────────╮
# │              CXX part              │
# ╰────────────────────────────────────╯
CPP 		= c++
CPPFLAGS	= -Wall -Wextra -Werror -I. -std=c++98
NAME		= Zombie
COMPILE		= $(CPP) $(CPPFLAGS)
# ╭────────────────────────────────────╮
# │               OPTIONS              │
# ╰────────────────────────────────────╯
RM			= rm -rf
# ╭────────────────────────────────────╮
# │               SOURCES              │
# ╰────────────────────────────────────╯
SRCS		= main.cpp \
			  Zombie.cpp \
			  newZombie.cpp \
			  randomChump.cpp
# ╭────────────────────────────────────╮
# │               OBJECTS              │
# ╰────────────────────────────────────╯
OBJS		= $(SRCS:.cpp=.o)
# ╭────────────────────────────────────╮
# │              COMMANDS              │
# ╰────────────────────────────────────╯
all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILE) $(OBJS) -o $@

%.o: %.cpp
	$(COMPILE) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re