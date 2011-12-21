#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>

#include "systeminfo.h"

#define MAX_CMD_LEN 32

typedef int (*ActionFun)(char *psz_xml);

typedef struct dispatch_table
{
    char *cmd;
    ActionFun action;
} dispatch_tab;

dispatch_tab  dis_tab[] = 
{
    {"login", NULL},                //登陆

    {"get_sysinfo_tmp", NULL},      //获取动态系统信息
    {"get_sysinfo_fixed", NULL},    //获取固定系统信息

    {"dfile", NULL},                //文件下载
    {"mkdir", NULL},                //新建文件夹
    {"mv", NULL},                   //移动文件
    {"rm", NULL},                   //删除文件
    {"ls", NULL},                   //列文件目录
    {"files", NULL},                //获取目录文件数

    {"get_service_status", NULL},   //获取服务状态
    {"set_service_status", NULL},   //设置服务状态

    {"get_basic_settings", NULL},   //获取基础设置
    {"set_basic_settings", NULL},   //设置基础设置

    {"getnetworkinfo", NULL},       //获取网络设置
    {"setnetworkinfo", NULL},       //设置网络设置

    {"ddns_set", NULL},             //获取DDNS设置
    {"ddns_get", NULL},             //设置DDNS设置

    {"getusers", NULL},             //获取用户列表
    {"newuser", NULL},              //新建用户
    {"setuserinfo", NULL},          //编辑用户
    {"deleteuser", NULL},           //删除用户
    {"searchusers", NULL},          //搜索用户

    {"setsysdefault", NULL},        //恢复默认

    {"updatesys", NULL},            //固件更新
    {NULL, NULL},
};

char* str_xml =
    "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
    "<xml>"
        "<session>"
            "<username>username</username>"
            "<passwd>passwd</passwd>"
        "</session>"
        "<cmd>get_sysinfo_fixed</cmd>"
        "<cmd>get_sysinfo_fixed1</cmd>"
        "<cmd>get_sysinfo_fixed2</cmd>"
        "<cmd>get_sysinfo_fixed3</cmd>"
        "<tag>tag</tag>"
    "</xml>";

xmlXPathObjectPtr get_nodeset(xmlDocPtr doc, const xmlChar *szXPath);
char* getcmdfromxml(char *psz_xml, char *psz_cmd_out);

int main()
{
    printf("%s\n", get_hostname());
    printf("%s\n", get_local_ip());
    char sz_cmd[MAX_CMD_LEN] = {0};

    char *psz_cmd = getcmdfromxml(str_xml, sz_cmd);
    if (NULL != psz_cmd)
    {
        printf("cmd = %s\n", psz_cmd);
    }
    return 0;
}

xmlXPathObjectPtr get_nodeset(xmlDocPtr doc, const xmlChar *szXPath)
{
    xmlXPathContextPtr  context;    //XPATH上下文指针
    xmlXPathObjectPtr   result;     //XPATH对象指针，用来存储查询结果

    context =xmlXPathNewContext(doc);   //创建一个XPath上下文指针
    if (NULL == context)
    {
        printf("context is NULL\n");
        return NULL;
    }

    //查询XPath表达式，得到一个查询结果
    result = xmlXPathEvalExpression(szXPath, context);

    xmlXPathFreeContext(context);   //释放上下文指针
    if (NULL == result)
    {
        printf("xmlXPathEvalExpression return NULL\n");
        return NULL;
    }

    //检查查询结果是否为空
    if (xmlXPathNodeSetIsEmpty(result->nodesetval))
    {
        xmlXPathFreeObject(result);
        printf("nodeset is empty\n");
        return NULL;
    }

    return result;
}

char* getcmdfromxml(char *psz_xml, char *psz_cmd_out)
{
    xmlDocPtr doc = xmlReadMemory(psz_xml, strlen(psz_xml), NULL,  "UTF-8", XML_PARSE_RECOVER);

    if (NULL == doc)
    {
        fprintf(stderr, "Document not parsed successfully.\n");
        return NULL;
    }

    xmlXPathObjectPtr result = get_nodeset(doc, BAD_CAST("/xml/cmd"));

    if (NULL != result)
    {
        xmlNodePtr      cur_node = NULL;
        xmlChar         *psz_value = NULL;

        cur_node = result->nodesetval->nodeTab[0];
        if (NULL != cur_node)
        {
            psz_value = xmlNodeGetContent(cur_node);
            if (NULL != psz_value)
            {
                strcpy(psz_cmd_out, (char*)psz_value);
                xmlFree(psz_value);
                return psz_cmd_out;
            }
        }
        xmlXPathFreeObject(result);
    }
    xmlFreeDoc(doc);

    return NULL;
}

