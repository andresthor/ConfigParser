#include "ConfigParser.h"


ConfigParser::ConfigParser() : config_(new CategoryMap()) {}


ConfigParser::~ConfigParser()
{
  delete config_;
}


ParameterMap& ConfigParser::operator[] (std::string key)
{
  return (*config_)[key];
}


bool ConfigParser::readFile(std::string filename)
{
  std::ifstream in(filename);

  configString_ = std::string((std::istreambuf_iterator<char>(in)),
                               std::istreambuf_iterator<char>());

  return parseString(configString_);
}


bool ConfigParser::readString(std::string configString)
{
  configString_ = configString;
  return parseString(configString_);
}


bool ConfigParser::parseString(std::string configString)
{

  std::regex category(REGEX_CATEGORY);

  if (std::regex_search(configString, category)) {

    for (std::sregex_iterator it(configString.begin(),
         configString.end(), category),
         end_it; it != end_it; ++it) {

      if (!parseCategory(it->str()))
        return false;
    }
  }
  else {
    // No category, but there might be rogue parameters
    std::string title = "";
    (*config_)[title] = ParameterMap();
    parseParameters(title, configString);
  }

  return true;
}


bool ConfigParser::parseCategory(std::string category)
{
  std::regex categoryTitle(REGEX_CATEGORY_TITLE);

  std::smatch sm;
  if (std::regex_search(category, sm, categoryTitle)) {
    std::string title = sm[1].str();

    (*config_)[title] = ParameterMap();
    parseParameters(title, sm.suffix().str());
    return true;
  }
  else {
    std::cout << "Couldn't find any categories in the conf string" << std::endl;
    return false;
    // TODO: React
  }
}


void ConfigParser::parseParameters(std::string category, std::string paramString)
{
  std::regex params(REGEX_PARAMETERS);

  for (std::sregex_iterator it(paramString.begin(),
       paramString.end(), params),
       end_it; it != end_it; ++it) {

    (*config_)[category][it->str(1)] = it->str(2);
  }
}


void ConfigParser::printConfig()
{

  for (auto category : (*config_) ){
    std::cout << category.first << std::endl;
    for (auto param : category.second) {
     std::cout << param.first << " = " << param.second << std::endl;
    }
    std::cout << std::endl;
  }
}
