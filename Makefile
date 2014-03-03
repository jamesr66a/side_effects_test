test: test.sh side_effects no_side_effects
	./test.sh

side_effects: side_effects.c test_file
	gcc -std=c89 -Wall -pedantic -o ./side_effects side_effects.c

no_side_effects: no_side_effects.c test_file
	gcc -std=c89 -Wall -pedantic -o ./no_side_effects no_side_effects.c

test_file:
	cat "The quick brown fox jumps over the lazy dog" > test_file

clean:
	rm tmp_file side_effects no_side_effects
