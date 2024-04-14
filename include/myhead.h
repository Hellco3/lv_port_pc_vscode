#ifndef _MYHEAD_H
#define _MYHEAD_H
struct user
{
	char name[50];
	char password[50];
};
//封装一个结构体来表示双向循环链表
struct singlelist
{
	//数据域
	struct user ldata;
	//指针域
	struct singlelist *next;
	struct singlelist *prev;
};
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "lv_drv_conf.h"
#include "fun.h"
#include "btn_style.h"
#include "font_style.h"
#include "list.h"
#include "list_btn.h"
#include "chat.h"
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>  
#include <linux/input.h>  //跟输入子系统模型有关的头文件
#include <dirent.h>
#include <time.h>
#include <unistd.h> 
#include <sys/mman.h>
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>  
#include <linux/input.h>  //跟输入子系统模型有关的头文件
#include <dirent.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <signal.h> //跟信号有关的头文件
#include <sys/shm.h> //跟共享内存有关的头文件
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h> //跟信号量有关的头文件
#include <pthread.h> //跟线程有关的头文件
#include <semaphore.h> //跟POSIX无名信号量有关的头文件
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#endif