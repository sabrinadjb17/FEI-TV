# Project: FEITV
# Makefile created by Dev-C++ 5.11

CPP      = g++.exe
CC       = gcc.exe
WINDRES  = windres.exe
OBJ      = menuUsuario.o videos.o playlist.o menuPlaylist.o main.o outrasFuncoes.o usuario.o
LINKOBJ  = menuUsuario.o videos.o playlist.o menuPlaylist.o main.o outrasFuncoes.o usuario.o
LIBS     = -L"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib" -L"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib" -static-libgcc
INCS     = -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include"
CXXINCS  = -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include/c++"
BIN      = FEITV.exe
CXXFLAGS = $(CXXINCS) 
CFLAGS   = $(INCS) 
RM       = rm.exe -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o $(BIN) $(LIBS)

menuUsuario.o: menuUsuario.c
	$(CC) -c menuUsuario.c -o menuUsuario.o $(CFLAGS)

videos.o: videos.c
	$(CC) -c videos.c -o videos.o $(CFLAGS)

playlist.o: playlist.c
	$(CC) -c playlist.c -o playlist.o $(CFLAGS)

menuPlaylist.o: menuPlaylist.c
	$(CC) -c menuPlaylist.c -o menuPlaylist.o $(CFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

outrasFuncoes.o: outrasFuncoes.c
	$(CC) -c outrasFuncoes.c -o outrasFuncoes.o $(CFLAGS)

usuario.o: usuario.c
	$(CC) -c usuario.c -o usuario.o $(CFLAGS)
