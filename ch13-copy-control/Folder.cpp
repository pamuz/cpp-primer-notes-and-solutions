#include "Folder.h"

void Folder::addMsg(Message *m) {
  messages.insert(m);
}

void Folder::remMsg(Message *m) {
  messages.erase(m);
}

void Folder::forEachMessage(void (*callable)(Message*)) {
  for (auto m : messages) {
    callable(m);
  }
}
