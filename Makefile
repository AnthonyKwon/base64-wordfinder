OBJS = main.o base64.o

b64t: $(OBJS)
	gcc $^ -o $@

%.o: %.c
	gcc -Wall -Werror -O3 -c $< -o $@

main.o: main.c base64.h
base64.o: base64.c base64.h

clean:
	rm -f b64t *.o
