#give PN the name of your c file wihich contains main
PN=assignment1
SHARED=ass

CFLAGS=-Wall -Werror -Itest

$(PN): $(PN).o $(SHARED).o
	gcc $(CFLAGS) $^ -o $(PN)

$(PN).o: $(PN).c
	gcc $(CFLAGS) -c $^ -o $(PN).o

$(SHARED).o: $(SHARED).c
	gcc $(CFLAGS) -c $^ -o $(SHARED).o 

clean:
	rm -rf $(PN) $(PN).o $(SHARED).o
	ls
