NAME = blackjack

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
SRCS = \
	src/utils.cpp	src/main.cpp

OBJDIR = obj

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(NAME)