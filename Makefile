CC = g++
EXEC = bitwise
CFLAG = -std=c++11

all: $(EXEC)

$(EXEC): 
	$(CC) -o $(EXEC) $(CFLAG) main.cpp

clean:
	rm -f $(EXEC)
