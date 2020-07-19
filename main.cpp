#include "xmlhandler.h"

using namespace std;

int main(int argc, char *argv[])
{
    XmlHandler handle("../test.xml");
//    handle.addRooNode(string("base"));
//    handle.nodeEditOperation(ADD_NODE,string("child1"),string("firsd child"));
//    handle.nodeEditOperation(ADD_NODE,string("child2"));
//    handle.nodeTraverseOperation(CHILD_NODE);
//    handle.nodeTraverseOperation(NEXT_NODE);
//    handle.nodeEditOperation(ADD_ATTRIBUTE,"attr1","this has a child");
//    handle.nodeEditOperation(ADD_NODE,"child3");
//    handle.writeDocToFile("test5");

    handle.nodeListOperation(LIST_CHILDREN);
    handle.nodeListOperation(LIST_PARENT);
    handle.nodeTraverseOperation(NEXT_NODE);
    handle.nodeRWOperation(READ_ELEMENT_CONTENT);
    handle.nodeTraverseOperation(CHILD_NODE);
    handle.nodeListOperation(LIST_CHILDREN);
    handle.nodeListOperation(LIST_ATTRIBUTES);
    handle.nodeTraverseOperation(NEXT_NODE);
    handle.nodeListOperation(LIST_CHILDREN);
    handle.nodeListOperation(LIST_HIERARCHY);
    handle.nodeListOperation(LIST_ATTRIBUTES);
    handle.nodeTraverseOperation(CHILD_NODE);
    handle.nodeTraverseOperation(NEXT_NODE);
    handle.nodeListOperation(LIST_ATTRIBUTES);
    handle.nodeTraverseOperation(CHILD_NODE);
    handle.nodeTraverseOperation(NEXT_NODE);
    handle.nodeListOperation(LIST_ATTRIBUTES);
    handle.nodeRWOperation(READ_ATTRIBUTE_NAME);
    handle.nodeRWOperation(READ_ATTRIBUTE_CONTENT);
    handle.nodeRWOperation(READ_ELEMENT_NAME);
    handle.nodeRWOperation(READ_ELEMENT_CONTENT);

    return 0;
}
