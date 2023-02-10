OBJS = main.o base64.o

b64t: $(OBJS)
	c++ $^ -o $@

%.o: %.cpp
	c++ -Wall -Werror -O3 -c $< -o $@

main.o: main.cpp base64.h
base64.o: base64.cpp base64.h

clean:
	rm -f b64t *.o
