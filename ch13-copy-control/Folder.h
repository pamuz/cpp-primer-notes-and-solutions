#ifndef __FOLDER_G_
#define __FOLDER_G_

#include <string>
#include <set>

class Message;

class Folder {
 public:
  Folder(std::string n): name(n) {}
  void addMsg(Message *m);
  void remMsg(Message *m);
  void forEachMessage(void (*)(Message*));

 private:
  std::string name;
  std::set<Message*> messages;
};

#endif
