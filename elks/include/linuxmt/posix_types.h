#ifndef LX86_LINUXMT_POSIX_TYPES_H
#define LX86_LINUXMT_POSIX_TYPES_H

#include <linuxmt/config.h>
#include <linuxmt/types.h>

/* This file is generally used by user-level software, so you need to
 * be a little careful about namespace pollution etc.  Also, we cannot
 * assume GCC is being used.
 */

#ifndef NULL
#define NULL		((void *) 0)
#endif

/* This allows for 20 file descriptors: if NR_OPEN is ever grown beyond
 * that you'll have to change this too. For now 20 fd's seem to be
 * enough for ELKS, so hopefully this won't need changing.
 *
 * Note that POSIX wants the FD_CLEAR(fd,fdsetp) defines to be in
 * <sys/time.h> (and thus <linux/time.h>) - but this is a more logical
 * place for them. Solved by having dummy defines in <sys/time.h>.
 *
 * Those macros may have been defined in <gnu/types.h>. But we always
 * use the ones here. 
 */

/*@-namechecks@*/

#ifdef CONFIG_SHORT_FILES

#undef __NFDBITS
#define __NFDBITS	(8 * sizeof(unsigned short))

#undef __FD_SETSIZE
#define __FD_SETSIZE	16

typedef __u16 __kernel_fd_set;

#else

#undef __NFDBITS
#define __NFDBITS	(8 * sizeof(unsigned long))

#undef __FD_SETSIZE
#define __FD_SETSIZE	20

typedef __u32 __kernel_fd_set;

#endif

/*@+namechecks@*/

#include <arch/posix_types.h>
#include <linuxmt/time.h>

#endif
