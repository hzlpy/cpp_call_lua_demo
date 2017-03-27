CC=g++
IDIR=../include
CFLAGS=-I$(IDIR)

ODIR=../obj
BDIR=../bin
LDIR=../lib

_OBJ=run_lua_file.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

_OBJ1=call_lua_func.o
OBJ1=$(patsubst %,$(ODIR)/%,$(_OBJ1))

_OBJ2=lua_callback.o
OBJ2=$(patsubst %,$(ODIR)/%,$(_OBJ2))

LIBS = -L$(LDIR) -llua -ldl

$(ODIR)/%.o: %.cpp
	$(CC) -g -c -o $@ $< $(CFLAGS)

run_lua_file: $(OBJ)
	$(CC) -g -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)

call_lua_func: $(OBJ1)
	$(CC) -g -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)

lua_callback: $(OBJ2)
	$(CC) -g -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o
