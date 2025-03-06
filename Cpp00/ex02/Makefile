# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Files
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = account_test

# Compile executable
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Clean object files
clean:
	rm -f $(OBJS)

# Clean all
fclean: clean
	rm -f $(TARGET)

# Recompile
re: fclean all

.PHONY: all clean fclean re
