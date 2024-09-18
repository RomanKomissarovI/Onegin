OBJFILES := color_print.o in_out.o main.o sort.o string_func.o compare.o
FLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: main.exe 

run: main.exe
	./main.exe

color_print.o: color_print.c
	@ g++ color_print.c -c $(FLAGS) -o color_print.o

in_out.o: in_out.c
	@ g++ in_out.c -c $(FLAGS) -o in_out.o

main.o: main.c
	@ g++ main.c -c $(FLAGS) -o main.o

sort.o: sort.c
	@ g++ sort.c -c $(FLAGS) -o sort.o

string_func.o: string_func.c
	@ g++ string_func.c -c $(FLAGS) -o string_func.o

compare.o: compare.c
	@ g++ compare.c -c $(FLAGS) -o compare.o

main.exe : $(OBJFILES)
	@ g++ $(FLAGS) $(OBJFILES) -o main.exe
