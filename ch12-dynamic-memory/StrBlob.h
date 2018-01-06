#include <string>
#include <memory>
#include <vector>
#include <stdexcept>
#include <utility>

// Forward declaration
class StrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;

 public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  size_type size() const { return data->size(); }
  bool empty() const { return data-> empty(); }
  // add and remove elements
  void push_back(const std::string &t) { data->push_back(t); }
  void pop_back();
  // element access
  std::string& front();
  std::string& back();
  StrBlobPtr begin();
  StrBlobPtr end();
 private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
 public:
 StrBlobPtr(): curr(0) {};
 StrBlobPtr(StrBlob &a, size_t sz = 0):
  wptr(a.data), curr(sz) {};
  std::string& deref() const;
  StrBlobPtr& incr();
  bool eq(StrBlobPtr&);
  
 private:
  std::shared_ptr<std::vector<std::string>>
    check(std::size_t, const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

