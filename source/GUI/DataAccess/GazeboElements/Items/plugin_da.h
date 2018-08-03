#ifndef PLUGIN_DA_H
#define PLUGIN_DA_H
#include "QtXml"

class plugin_DA
{
public:
    plugin_DA();
    std::string GetName();
    void SetName(std::string);
    std::string GetFilename();
    void SetFilename(std::string);
    void Write(QXmlStreamWriter* );
    void print();

    std::string name;
    std::string filename;
    std::vector<std::string> parameters;
    std::vector<std::string> values;
};

#endif // PLUGIN_DA_H
