# ╔════════════════════════════════════════════════════════════════════════╗
# ║                       Makefile for C++ exercises                       ║
# ╚════════════════════════════════════════════════════════════════════════╝
# ╭────────────────────────────────────╮
# │              CXX part              │
# ╰────────────────────────────────────╯
CPP 		= c++
CPPFLAGS	= -Wall -Wextra -Werror -I. -std=c++98
CPPFLAGS	= -MMD -MP
NAME		= PhoneBook
COMPILE		= $(CPP) $(CPPFLAGS)
# ╭────────────────────────────────────╮
# │               OPTIONS              │
# ╰────────────────────────────────────╯
RM			= rm -rf
# ╭────────────────────────────────────╮
# │               SOURCES              │
# ╰────────────────────────────────────╯
SRCS		= Contact.cpp \
			  PhoneBook.cpp \
			  main.cpp
# ╭────────────────────────────────────╮
# │               OBJECTS              │
# ╰────────────────────────────────────╯
OBJS		= $(SRCS:.cpp=.o)
# ╭────────────────────────────────────╮
# │            DEPENDENCIES            │
# ╰────────────────────────────────────╯
DEPS       = $(SRCS:.cpp=.d)
-include $(DEPS)
# ╭────────────────────────────────────╮
# │              COMMANDS              │
# ╰────────────────────────────────────╯
all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILE) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(COMPILE) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: clean all fclean re