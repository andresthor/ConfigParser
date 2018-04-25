#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <streambuf>
#include <regex>
#include <map>

using ParameterMap = std::map<std::string, std::string>;
using CategoryMap = std::map<std::string, ParameterMap>;

const std::string REGEX_CATEGORY = "(\\[.*\\])([^\\[]*)";
const std::string REGEX_CATEGORY_TITLE = "\\[(.*)\\]";
const std::string REGEX_PARAMETERS = "([[:alnum:]]+)[\\s:=]+([[:alnum:]]+)\\n";


class ConfigParser
{
public:
  ConfigParser();
  ~ConfigParser();

  bool parseCategory(std::string category);
  void parseParameters(std::string category, std::string paramString);
  bool parseString(std::string configString);

  bool readFile(std::string filename);
  bool readString(std::string configString);

  void printConfig();

  ParameterMap& operator[] (std::string key);

private:
  CategoryMap* config_;
  std::string configString_;
};


#endif /* CONFIGPARSER_H */
