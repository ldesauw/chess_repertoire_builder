CXX=g++
RM=rm -f
CPPFLAGS=-g -I/usr/include -Wall
LDFLAGS=
LDLIBS=

NAME=chessrepbuilder
SRCS=$(wildcard **/*.cpp)
OBJS=$(subst .cpp,.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)

clean:
	$(RM) $(OBJS)

deepclean: clean
	$(RM) $(NAME)

re: clean $(NAME)