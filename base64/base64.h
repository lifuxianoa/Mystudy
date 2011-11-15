#ifndef __BASE64_H__
#define __BASE64_H__

char * encodeBase64(unsigned char *ptrInData, unsigned long ulInLen, 
        unsigned char *ptrOutData, unsigned long *ulOutLen);

char * decodeBase64(unsigned char *ptrInData, unsigned long ulInLen,
        unsigned char *ptrOutData, unsigned long *ulOutLen);

#endif
