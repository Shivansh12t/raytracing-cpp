CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g -ISDL2/include
LDFLAGS = -LSDL2/lib -lmingw32 -lSDL2main -lSDL2 
TARGET = out.exe
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
RM = del /f
# SDLFLAGS = -ISDL2/include -LSDL2/lib -lmingw32 -lSDL2main -lSDL2

# Default Target
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Pattern rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS)
