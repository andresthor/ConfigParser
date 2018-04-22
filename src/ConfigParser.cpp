#include "ConfigParser.h"

ConfigParser::ConfigParser() : config_(new categorymap()) {}

ConfigParser::~ConfigParser()
{
  delete config_;
}


parametermap& ConfigParser::operator[] (string key)
{
  return (*config_)[key];
}


bool ConfigParser::read(string filename)
{
  cout << "ConfigParser::read()\n";
  
  ifstream in(filename);

  configString_ = string((istreambuf_iterator<char>(in)),
                          istreambuf_iterator<char>());

  return parseString(configString_);
}


bool ConfigParser::parseString(string configString)
{

  regex category(REGEX_CATEGORY);

  for (sregex_iterator it(configString.begin(), configString.end(), category),
       end_it; it != end_it; ++it) {

    if (!parseCategory(it->str()))
      return false;
  }

  return true;

}


bool ConfigParser::parseCategory(string category)
{
  regex categoryTitle(REGEX_CATEGORY_TITLE);
  
  smatch sm;
  if (regex_search(category, sm, categoryTitle)) {
    string title = sm[1].str();

    (*config_)[title] = parametermap();
    parseParameters(title, sm.suffix().str());
    return true;
  }
  else {
    cout << "Couldn't find any categories in the config string" << endl;
    return false;
    // TODO: React
  }
}


void ConfigParser::parseParameters(string category, string paramString)
{
  regex params(REGEX_PARAMETERS);
  
  for (sregex_iterator it(paramString.begin(), paramString.end(), params),
       end_it; it != end_it; ++it) {
    (*config_)[category][it->str(1)] = it->str(2);
  }
}


void ConfigParser::printConfig()
{

  for (auto category : (*config_) ){
    cout << category.first << endl;
    for (auto param : category.second) {
     cout << param.first << " = " << param.second << endl; 
    }
    cout << endl;
  }
}
