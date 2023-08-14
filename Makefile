CC = g++ -g3 -g -std=c++11 

ask3: main.o creature.o good_creature.o bad_creature.o creature_society.o other.o 

	$(CC) -o ask3 main.o creature.o good_creature.o bad_creature.o creature_society.o other.o  -lm

main.o: main.cpp creature.cpp good_creature.cpp bad_creature.cpp creature_society.cpp other.cpp

	$(CC) -c main.cpp creature.cpp good_creature.cpp bad_creature.cpp creature_society.cpp other.cpp

creature.o: creature.cpp

	$(CC) -c creature.cpp

good_creature.o: good_creature.cpp

	$(CC) -c good_creature.cpp

bad_creature.o: bad_creature.cpp

	$(CC) -c bad_creature.cpp

creature_society.o: creature_society.cpp

	$(CC) -c creature_society.cpp

other.o: other.cpp

	$(CC) -c other.cpp

run:

	./ask3 20 100 2 3 3

valgrind:

	valgrind --leak-check=yes ./ask3 20 100 2 3 3

gdb:
	gdb ./ask3 20 100 2 3 3

clean: 

	rm -f *.o

	
	

