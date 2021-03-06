#ifndef _STDBOOL_H
#define _STDBOOL_H

/* believe it or not but the Single Unix Specification actually
 * specifies this header, see
 * http://www.opengroup.org/onlinepubs/007904975/basedefs/stdbool.h.html */

#if !defined(__cplusplus)

//#define bool _Bool
typedef unsigned char bool;
#define true 1
#define false 0
#define __bool_true_false_are_defined 1

#endif

#endif
