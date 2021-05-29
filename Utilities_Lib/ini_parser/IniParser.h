/**
 *  @file IniParser.h
 *
 *  @date 2021-05-28
 *
 *  @author aron566
 *
 *  @brief ini文件解析
 *
 *  @version V1.0
 */
#ifndef INIPARSER_H
#define INIPARSER_H
/** Includes -----------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
/** Private includes ---------------------------------------------------------*/
#include <QObject>
/** Private defines ----------------------------------------------------------*/
using namespace std;

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#  if defined(UTILITIES_LIBRARY)
#    define USER_INI_PARSER_EXPORT Q_DECL_EXPORT
#  else
#    define USER_INI_PARSER_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define USER_INI_PARSER_EXPORT
#endif
QT_END_NAMESPACE

/** Exported typedefines -----------------------------------------------------*/
struct ConfigINIEntry{
    ConfigINIEntry():isComment(false){}
    string index;
    string name;
    string value;
    string comment;
    bool isComment;
};
/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/
/**
 * @brief The IniParser class
 */
class USER_INI_PARSER_EXPORT IniParser : public QObject
{
    Q_OBJECT
public:
    explicit IniParser(const char *fileName, bool autoCreate = false, QObject *parent = nullptr);
    IniParser(QObject *parent = nullptr);
    ~IniParser();

public:
    /**
     * @brief set_ini_config_fileName
     * @param file_name
     */
    void set_ini_config_fileName(QString &file_name);

    /**
     * @brief writeConfigFile
     * @param fileName
     */
    void writeConfigFile(const char *fileName = nullptr);

    /***********getter*************/
    bool getBoolValue(const char* index, const char *name);
    int getIntValue(const char* index, const char *name);
    float getFloatValue(const char* index, const char *name);
    const char* getStringValue(const char* index, const char *name);

    /***********setter*************/
    void setBoolValue(const char* index, const char *name, bool value);
    void setIntValue(const char* index, const char *name, int value);
    void setFloatValue(const char* index, const char *name, float value);
    void setStringValue(const char *index, const char* name, const char* value);

    /******* for test only *******/
    void printAll();

    /******* get all Entry *******/
    vector<ConfigINIEntry> datas;
private:
    char str[4096];//for temp string data
    void setStringValueWithIndex(const char *index, const char* name, const char* value);
    char iniFileName[128];
    char *data;
    const char (*lineData)[4096];
    void loadConfigFile();
    fstream *fStream;
    bool autoSave;
    bool autoCreate;
};

#endif  //INIPARSER_H
/******************************** End of file *********************************/
