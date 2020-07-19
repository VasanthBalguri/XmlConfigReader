#include "xmlhandler.h"

string XmlHandler::nodeRWOperation(NODE_RW_OPERATION operation, string content)
{
    string output = "";
    if(p_node != NULL)
    {
        if(p_attribute == NULL)
        {
            cout<<"attribute is not loaded"<<endl;
            p_attribute = p_node->properties;
        }
        switch(operation)
        {
        case READ_ELEMENT_NAME:
        {
            output = (char*)p_node->name;

            break;
        }
        case READ_ELEMENT_CONTENT:
        {
            if(p_node->content)
                output = (char*)p_node->content;
            else
               cout<<"no content set"<<endl;
            break;
        }
        case READ_ATTRIBUTE_NAME:
        {
            if(p_attribute != NULL)
            output = (char*)p_attribute->name;
            else
            cout<<"no attribute set"<<std::endl;
            break;
        }
        case READ_ATTRIBUTE_CONTENT:
        {
            if(p_attribute != NULL)
            output = (char*)p_attribute->children->content;
            else
            cout<<"has no attributes"<<std::endl;
            break;
        }
        case WRITE_ELEMENT_CONTENT:
        {
            xmlNodeAddContent(p_node,BAD_CAST content.c_str());
            break;
        }
        case WRITE_ATTRIBUTE_CONTENT:
        {
            if(p_attribute != NULL)
            xmlSetProp(p_node,p_attribute->name,BAD_CAST content.c_str());
            else
            cout<<"has no attributes"<<std::endl;
            break;
        }
        }
    }
    else
    {
        cout<<"node not set"<<std::endl;
    }
cout<<output<<endl;
    return output;
}

vector<string> XmlHandler::nodeListOperation(NODE_LIST_OPERATION operation)
{
    vector<string> list;
    if(p_node != NULL)
    {
        switch(operation)
        {
        case LIST_CHILDREN:
        {
          if(p_node->children != NULL)
          {
           for(xmlNodePtr cur_node = p_node->children;cur_node;cur_node = cur_node->next)
           {
               list.push_back(string((char*)cur_node->name));
               cout<<(char*)cur_node->name<<endl;
           }
          }
          else
          {
              cout<<"leaf node"<<std::endl;
          }
           break;
        }
        case LIST_ATTRIBUTES:
        {
            if(p_node->properties != NULL)
            {
                for(xmlAttrPtr cur_attr = p_node->properties;cur_attr;cur_attr = cur_attr->next)
                {
                    list.push_back(string((char*)cur_attr->name));
                    cout<<(char*)cur_attr->name<<endl;
                }
            }
            else
            {
                cout<<"no attributes"<<std::endl;
            }

            break;
        }
        case LIST_HIERARCHY:
        {
            for(xmlNodePtr cur_node = p_node;cur_node->type != XML_DOCUMENT_NODE;cur_node = cur_node->parent)
            {
                list.push_back(string((char*)cur_node->name));
                cout<<(char*)cur_node->name<<endl;
            }
            break;
        }
        case LIST_PARENT:
        {
            if(p_node->parent && (p_node->parent->type != XML_DOCUMENT_NODE))
            {
                list.push_back(string((char*)p_node->parent->name));
                cout<<(char*)p_node->parent->name<<endl;
            }
            else
            {
               cout<<"root node"<<std::endl;
            }
            break;
        }
        }
    }
    else
    {
        cout<<"node not set"<<std::endl;
    }

    return list;
}

bool XmlHandler::nodeEditOperation(NODE_EDIT_OPERATION operation, string name, string content)
{
    if(p_node != NULL)
    {
        if(p_attribute == NULL)
        {
            p_attribute = p_node->properties;
        }
        switch(operation)
        {
        case ADD_NODE:
        {
            xmlNewChild(p_node, NULL, BAD_CAST name.c_str(), BAD_CAST content.c_str());
            break;
        }
        case REMOVE_NODE:
        {
            xmlNodePtr cur_node;
            cur_node = p_node->parent;
            xmlUnlinkNode(p_node);
            p_node = cur_node;
            break;
        }
        case ADD_ATTRIBUTE:
        {
            p_attribute = xmlSetProp(p_node,BAD_CAST name.c_str(),BAD_CAST content.c_str());
            break;
        }
        case REMOVE_ATTRIBUTE:
        {
            xmlRemoveProp(p_attribute);
            break;
        }
        }
    }
    else
    {
       cout<<"node not set"<<std::endl;
       return false;
    }

    return true;
}

bool XmlHandler::nodeTraverseOperation(NODE_TRAVERSE_OPERATION operation)
{
    if(p_node !=NULL)
    {
        if(p_attribute == NULL)
        {
            p_attribute = p_node->properties;
        }
        switch(operation)
        {
        case NEXT_NODE:
        {
            if(p_node->next)
            {
                p_node = p_node->next;
                p_attribute = p_node->properties;
                cout<<"next node:"<<(char*)p_node->name<<std::endl;
            }
            else
            {
                cout<<"last node"<<std::endl;
                return false;
            }
            break;
        }
        case PREV_NODE:
        {
            if(p_node->prev)
            {
                p_node = p_node->prev;
                p_attribute = p_node->properties;
                cout<<"prev node:"<<(char*)p_node->name<<std::endl;
            }
            else
            {
                cout<<"first node"<<std::endl;
                return false;
            }
            break;
        }
        case CHILD_NODE:
        {
            if(p_node->children)
            {
                p_node = p_node->children;
                p_attribute = p_node->properties;
                cout<<"first child node:"<<(char*)p_node->name<<std::endl;
            }
            else
            {
                cout<<"leaf node"<<std::endl;
                return false;
            }
            break;
        }
        case PARENT_NODE:
        {
            if(p_node->parent && (p_node->parent->type != XML_DOCUMENT_NODE))
            {
                p_node = p_node->parent;
                p_attribute = p_node->properties;
                cout<<"parent node:"<<(char*)p_node->name<<std::endl;
            }
            else
            {
                cout<<"root node"<<std::endl;
                return false;
            }
            break;
        }
        case ROOT_NODE:
        {
            p_node = p_doc->children;
            cout<<"root node:"<<(char*)p_node->name<<std::endl;
            break;
        }
        case NEXT_ATTRIBUTE:
        {
            if(p_attribute->next)
            {
                p_attribute = p_attribute->next;
                cout<<"next attribute"<<(char*)p_attribute->name<<std::endl;
            }
            else
            {
                cout<<"last attribute"<<std::endl;
                return false;
            }
            break;
        }
        case PREV_ATTRIBUTTE:
        {
            if(p_attribute->prev)
            {
                p_attribute = p_attribute->prev;
                cout<<"prev attribute"<<(char*)p_attribute->name<<std::endl;
            }
            else
            {
                cout<<"first attribute"<<std::endl;
                return false;
            }
            break;
        }
        }
    }
    else
    {
        cout<<"node not selected"<<std::endl;
        return false;
    }
    return true;
}
