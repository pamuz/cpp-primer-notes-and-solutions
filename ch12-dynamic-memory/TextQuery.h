#ifndef __TEXT_QUERY_G
#define __TEXT_QUERY_G

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <sstream>

class QueryResult;

class TextQuery {
 public:
  using line_no = std::vector<std::string>::size_type;
  TextQuery(std::ifstream&);
  QueryResult query(const std::string &) const;
 private:
  std::shared_ptr<std::vector<std::string>> file;
  std::map<std::string,
    std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
  friend std::ostream &print(std::ostream &os, const QueryResult &qr);
 public:
  QueryResult(std::string s,
              std::shared_ptr<std::set<TextQuery::line_no>> p,
              std::shared_ptr<std::vector<std::string>> f):
  sought(s), lines(p), file(f) {}
 private:
  std::string sought;
  std::shared_ptr<std::set<TextQuery::line_no>> lines;
  std::shared_ptr<std::vector<std::string>> file;
};

#endif
