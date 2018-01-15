#ifndef _STRVEC_G_
#define _STRVEC_G_

#include <string>
#include <memory>

class StrVec {
 public:
  StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec &s);
  StrVec& operator=(const StrVec &s);
  StrVec(StrVec &&s) noexcept;
  ~StrVec();
  void push_back(const std::string s);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return cap; }
 private:
  std::string *elements; // First
  std::string *first_free; // Next available
  std::string *cap; // 1 past the end
  std::allocator<std::string> alloc;
  void check_n_alloc() { if (size() == capacity()) reallocate(); }
  std::pair<std::string *, std::string *> alloc_n_copy
    (const std::string*, const std::string *);
  void free();
  void reallocate();
};

#endif
