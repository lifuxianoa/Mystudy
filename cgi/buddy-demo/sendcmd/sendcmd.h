#ifndef __SEND_CMD_H__
#define __SEND_CMD_H__

/*
   说明：发送命令并等待应答
   参数：
    psz ---- 字符串指针，指向要发送的数据
    length ---- 要发送的数据长度
    timeout ---- 等待应答的超时时间，单位是秒，为0时表示禁止超时。
            如果超时没有应答，返回值为NULL
    
  返回值：成功时返回接收缓冲区指针，注意使用完后需要调用者自己调用free释放内存。
        否则会造成内存泄露。
        失败时，返回NULL
   */
char* sendcmd_and_getresp(const char *psz, int length, int timeout);

#endif

