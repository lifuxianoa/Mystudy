#include <stdio.h>
#include <libxml/parser.h>

int xml_read(xmlNodePtr node);

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("Usage: %s docname\n", argv[0]);
        return 0;
    }

    char *pszDocName = argv[1];
    xmlDocPtr doc = xmlReadFile(pszDocName, "UTF-8", XML_PARSE_RECOVER);
    if (NULL == doc)
    {
        fprintf(stderr, "Document not parsed successfully.\n");
        return -1;
    }

    xmlNodePtr cur_node = xmlDocGetRootElement(doc); //确定文档根节点
    if (NULL == cur_node)
    {
        fprintf(stderr, "empty document.\n");
        xmlFreeDoc(doc);
        return -1;
    }

    int i_ret = xml_read(cur_node);
    printf("i_ret = %d\n", i_ret);
    return 0;
}

int xml_read(xmlNodePtr cur_node)
{
    xmlChar *psz_value = NULL;
    xmlAttrPtr attrPtr = NULL;

    if (NULL == cur_node)
    {
        return -1;
    }

    if (XML_TEXT_NODE != cur_node->type)
    {
        printf("%s:", cur_node->name);
    }

    //节点属性
    attrPtr = cur_node->properties;
    while (NULL != attrPtr)
    {
        printf("\tattribute name:%s", attrPtr->name);
        psz_value = xmlGetProp(cur_node, attrPtr->name);
        if (NULL != psz_value)
        {
            printf("value:%s", psz_value);
        }
        xmlFree(psz_value);
        attrPtr = attrPtr->next;
    }

    //Content
    if (XML_TEXT_NODE == cur_node->type)
    {
        psz_value = xmlNodeGetContent(cur_node);
        if (NULL != psz_value)
        {
            printf("\tcontent:%s", psz_value);
            xmlFree(psz_value);
        }
    }

    printf("\n");

    cur_node = cur_node->children;
    while(NULL != cur_node)
    {
        xml_read(cur_node);
        cur_node = cur_node->next;
    }

    return 0;
}
