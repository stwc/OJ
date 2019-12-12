ECHO   = /bin/echo -e
CFLAGS = --std=c++11 -Wall -Wshadow -O2
EXEC = test
OBJS = hello.o

all: ${EXEC}

%.o: %.cpp
	@$(ECHO) "> compiling: \033[34m$<\033[0m -> \033[01m\033[34m$@\033[0m"
	$(CXX) $(CFLAGS) -c -o $@ $<

${EXEC}: $(OBJS)
	$(CXX) -o $@ $^

.PHONY: clean
clean:
	$(RM) ${EXEC} *.o
