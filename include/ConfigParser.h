#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <streambuf>
#include <regex>
#include <map>


using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::istreambuf_iterator;
using std::regex;
using std::sregex_iterator;
using std::regex_search;
using std::smatch;
using std::map;


using parametermap = map<string, string>;
using categorymap = map<string, parametermap>;


const string REGEX_CATEGORY = "(\\[.*\\])([^\\[]*)";
const string REGEX_CATEGORY_TITLE = "\\[(.*)\\]";
const string REGEX_PARAMETERS = "([[:alnum:]]+)[\\s:=]+([[:alnum:]]+)\\n";


class ConfigParser
{
public:
  ConfigParser();
  ~ConfigParser();

  bool read(string filename);
  bool parseString(string configString);
  void parseParameters(string category, string paramString);
  bool parseCategory(string category);
  void printConfig();

  parametermap& operator[] (string key);


private:
  categorymap* config_;
  string configString_;
};

#endif /* CONFIGPARSER_H */
