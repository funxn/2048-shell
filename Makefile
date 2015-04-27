CC		= gcc
LD		= gcc

CFLAGS		= -c -I include/
LIBFLAGS	= 
LDFLAGS		=

TARGET		= 2048
OBJS		= main.o drawGrid.o changeState.o random_gen.o

# OPTIONS:
.PHONY: everything clean

everything: $(TARGET)

clean: 
	rm -f $(OBJS) $(TARGET)

### dependences description:
$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $(LIBFLAGS) -o $(TARGET) $(OBJS)

main.o: maindir/main.c include/proto.h
	$(CC) $(CFLAGS) -o $@ $<

drawGrid.o: drawdir/drawGrid.c
	$(CC) $(CFLAGS) -o $@ $<

changeState.o: maindir/changeState.c include/proto.h include/global.h
	$(CC) $(CFLAGS) -o $@ $<

random_gen.o: maindir/random_gen.c
	$(CC) $(CFLAGS) -o $@ $<

