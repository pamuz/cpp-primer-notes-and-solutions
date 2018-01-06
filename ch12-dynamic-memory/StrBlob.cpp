#include "StrBlob.h"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il):
  data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const
{
  if (i >= data->size())
    throw std::out_of_range(msg);
}

std::string& StrBlob::front()
{
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string& StrBlob::back()
{
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back()
{
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
  auto ret = wptr.lock();
  if (!ret)
    throw std::runtime_error("unbound StrBlobPtr");
  if (i >= ret->size())
    throw std::out_of_range(msg);
  return ret;
}

std::string& StrBlobPtr::deref() const
{
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
  check(curr, "increment at end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end()
  { auto ret = StrBlobPtr(*this, data->size());
    return ret; }


bool StrBlobPtr::eq(StrBlobPtr& other) {
  return curr == other.curr;
};
