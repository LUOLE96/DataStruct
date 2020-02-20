CFLAGS+=-Wall

all:ball_clock

ball_clock:sqstack.o main.o queue.o
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	rm ball_clock *.o -rf
