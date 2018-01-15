#ifndef __MESSAGE_G_
#define __MESSAGE_G_

#include <string>
#include <set>
#include "Folder.h"

class Message {
  friend class Folder;
  friend void swap(Message &lhs, Message &rhs);

 public:
  explicit Message(const std::string &str=""): contents(str) {}
  Message(const Message &);
  Message& operator=(const Message&);
  ~Message();
  void save(Folder&);
  void remove(Folder&);
  std::string get_contents() { return contents; };
 private:
  std::string contents;
  std::set<Folder*> folders;
  void add_to_Folders(const Message&);
  void remove_from_Folders();
};

#endif
