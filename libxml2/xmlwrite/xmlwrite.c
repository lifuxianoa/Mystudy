#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main()
{
    xmlDocPtr doc = xmlNewDoc(BAD_CAST"1.0");
    xmlNodePtr root_node = xmlNewNode(NULL, BAD_CAST"root");

    //设置根节点
    xmlDocSetRootElement(doc, root_node);

    //在根结点中创建节点
    xmlNewTextChild(root_node, NULL, BAD_CAST"newNode1",
            BAD_CAST"newNode1 content");
    xmlNewTextChild(root_node, NULL, BAD_CAST"newNode2",
            BAD_CAST"newNode2 content");
    xmlNewTextChild(root_node, NULL, BAD_CAST"newNode3",
            BAD_CAST"newNode3 content");

    //创建一个节点，设置其内容和属性，然后加入根节点
    xmlNodePtr node = xmlNewNode(NULL, BAD_CAST"node2");
    xmlNodePtr content = xmlNewText(BAD_CAST"NODE_CONTENT");
    xmlAddChild(root_node, node);
    xmlAddChild(node, content);
    xmlNewProp(node, BAD_CAST"attribute", BAD_CAST"yes");

    //创建一个儿子及孙子节点
    node = xmlNewNode(NULL, BAD_CAST"son");
    xmlAddChild(root_node, node);

    xmlNodePtr grandson = xmlNewNode(NULL, BAD_CAST"grandson");
    xmlAddChild(node, grandson);
    //xmlAddChild(grandson, xmlNewText(BAD_CAST"This is a grandson node"));

    //存储xml文档
    int nRel = xmlSaveFile("CreatedXml.xml", doc);

    if (-1 != nRel)
    {
        printf("一个XML文档被创建，写入%d个字节\n", nRel);
    }
    xmlFreeDoc(doc);
    return 0;
}

