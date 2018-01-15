CPPFLAGS ?= "--std=c++0x"

all: exercise-13-5 exercise-13-8 exercise-13-11 exercise-13-17 exercise-13-18 exercise-13-19 Message.o Folder.o chat StrVec.o StrVecUser move-test

exercise-13-5:
exercise-13-8:
exercise-13-11:
exercise-13-17:
exercise-13-18:
exercise-13-19:
Message.o: Message.h Message.cpp
Folder.o: Folder.h Folder.cpp
chat: Message.o Folder.o chat.cpp
	$(CXX) $(CPPFLAGS) -o chat Folder.o Message.o chat.cpp 
StrVec.o: StrVec.h StrVec.cpp
StrVecUser: StrVecUser.cpp StrVec.o
	$(CXX) $(CPPFLAGS) -o StrVecUser StrVec.o StrVecUser.cpp
move-test:
