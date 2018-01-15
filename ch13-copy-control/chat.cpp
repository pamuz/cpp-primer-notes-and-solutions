#include "Message.h"
#include "Folder.h"
#include <iostream>

int main(int argc, char *argv[argc])
{
  Folder inbox("inbox");
  Folder work("work");
  Folder favorites("favorites");

  Message hello_msg("Hello");
  hello_msg.save(inbox);

  Message inquiry_msg("I want to inquiry about a job position");
  inquiry_msg.save(inbox);
  inquiry_msg.save(work);

  Message hello_msg_copy;
  hello_msg_copy = hello_msg;

  inbox.remMsg(&hello_msg_copy);

  std::cout << "Inbox messages: " << std::endl;

  inbox.forEachMessage([] (Message *m) {
      std::cout << m->get_contents() << std::endl;
    });

  std::cout << std::endl << "Work messages: " << std::endl;
  work.forEachMessage([] (Message *m) {
      std::cout << m->get_contents() << std::endl;
    });

  std::cout << std::endl << "Favorite messages: " << std::endl;
  favorites.forEachMessage([] (Message *m) {
      std::cout << m->get_contents() << std::endl;
    });
  
  return 0;
}
