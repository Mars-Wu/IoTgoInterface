
main: *.c *.h
	gcc -o $@ *.c

clean:
	rm main

.PHONY: clean
