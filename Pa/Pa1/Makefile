CPPFLAGS_L = -std=c++11 -fsanitize=address,leak,undefined
CPPFLAGS = -std=c++11
OBJECTS = course_database.o course.o main.o student_database.o student.o swap_list.o system.o wait_list.o
ZIPFILES = student.cpp swap_list.cpp wait_list.cpp system.cpp course.cpp
all: pa1.exe
leak: pa1_leak.exe
zip: submit.zip

pa1.exe: $(OBJECTS)
	g++ -o $@ $(CPPFLAGS) $^

pa1_leak.exe: $(OBJECTS)
	g++ -o $@ $(CPPFLAGS_L) $^

cleanZip:
	rm  -f AAA_submit.zip

submit.zip: cleanZip
	zip -r AAA_submit.zip $(ZIPFILES)

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	rm  -f  *.o *.exe

