#ifndef __SCULL_H__
#define __SCULL_H__

#include <linux/cdev.h>

#define SCULL_DEBUG

#undef PDEBUG   /* undef it, just in case */
#ifdef SCULL_DEBUG
#ifdef __KERNEL__

/* This one if debugging is on, and kernel space */
#define PDEBUG(fmt, args...) printk( KERN_NOTICE "scull: " fmt, ##args)
#else

/* This one for user space */
#define PDEBUG(fmt, args...) fprintf(stderr, fmt, ##args)
#endif
#else
#define PDEBUG(fmt, args...)    /* not debugging: nothing */
#endif

#undef PDEBUGG
#define PDEBUGG(fmt, args...)    /* nothing: it's a placeholder */

#ifndef SCULL_MAJOR
#define SCULL_MAJOR 0
#endif

#ifndef SCULL_MINOR
#define SCULL_MINOR 0
#endif

#ifndef SCULL_NR_DEVS
#define SCULL_NR_DEVS 4
#endif

#ifndef SCULL_QUANTUM
#define SCULL_QUANTUM 4000
#endif

#ifndef SCULL_QSET
#define SCULL_QSET 1000
#endif

struct scull_qset
{
    void **data;
    struct scull_qset *next;
};

struct scull_dev
{
    struct scull_qset *data;    /* Pointer to first quantum set */
    int quantum;                /* the current quantum size */
    int qset;                   /* the current array size */
    unsigned long size;         /* amount of data stored here */
    unsigned int access_key;    /* used by sculluid and scullpriv */
    struct semaphore sem;       /* mutual exclusion semaphore */
    struct cdev cdev;           /* Char device structure */
};

#endif

