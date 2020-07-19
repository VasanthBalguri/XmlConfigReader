#ifndef XMLHANDLER_H
#define XMLHANDLER_H
#include <iostream>
#include <string>
#include <vector>
#include <libxml/parser.h>
#include <libxml/tree.h>

using namespace std;

enum NODE_RW_OPERATION {
    READ_ELEMENT_NAME = 0,
    READ_ELEMENT_CONTENT = 1,
    READ_ATTRIBUTE_NAME = 2,
    READ_ATTRIBUTE_CONTENT = 3,
    WRITE_ELEMENT_CONTENT = 4,
    WRITE_ATTRIBUTE_CONTENT = 5,
};
enum NODE_LIST_OPERATION{
    LIST_CHILDREN = 0,
    LIST_ATTRIBUTES = 1,
    LIST_PARENT = 2,
    LIST_HIERARCHY = 3
};
enum NODE_EDIT_OPERATION {
    ADD_NODE = 0,
    REMOVE_NODE = 1,
    ADD_ATTRIBUTE = 2,
    REMOVE_ATTRIBUTE = 3
};
enum  NODE_TRAVERSE_OPERATION{
    NEXT_NODE = 0,
    PREV_NODE = 1,
    CHILD_NODE = 2,
    PARENT_NODE = 3,
    ROOT_NODE = 4,
    NEXT_ATTRIBUTE = 5,
    PREV_ATTRIBUTTE  =6
};

/*
 * operations will be performed with respect to pointing node
 * */
class XmlHandler
{
    xmlDocPtr p_doc = NULL;
    xmlNodePtr p_node = NULL;
    xmlAttrPtr p_attribute = NULL;
    xmlChar* p_data = NULL;
public:
    XmlHandler()
    {
        cout<<"new xml"<<std::endl;
        p_doc = xmlNewDoc(BAD_CAST "1.0");
    }

    XmlHandler(string path)
    {
        cout<<"loading file"<<std::endl;
        p_doc = xmlReadFile(path.c_str(), NULL, 0);
        p_node = xmlDocGetRootElement(p_doc);
    }

    ~XmlHandler()
    {
        cout<<"cleaning up data"<<std::endl;
        xmlFreeDoc(p_doc);
        xmlCleanupParser();
    }

    void readFile(string path)
    {
        p_doc = xmlReadFile(path.c_str(), NULL, 0);
    }

    void writeDocToFile(string path)
    {
        cout<<"saving changes"<<std::endl;
        xmlSaveFormatFileEnc(path.c_str(), p_doc, "UTF-8", 1);
    }

    void addRooNode(string name)
    {
        p_node = xmlNewNode(NULL, BAD_CAST name.c_str());
        xmlDocSetRootElement(p_doc, p_node);
        cout<<(char*)p_node->name<<endl;
    }

    string nodeRWOperation(NODE_RW_OPERATION operation,string content = "");
    vector<string> nodeListOperation(NODE_LIST_OPERATION operation);
    bool nodeEditOperation(NODE_EDIT_OPERATION operation,string name,string content = "");
    bool nodeTraverseOperation(NODE_TRAVERSE_OPERATION operation);

};

#endif // XMLHANDLER_H
