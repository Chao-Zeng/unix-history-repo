/*-
 * Copyright (c) 1991 The Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.redist.c%
 *
 *	@(#)unistd.h	5.4 (Berkeley) %G%
 */

#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/unistd.h>

#define	 STDIN_FILENO	0	/* standard input file descriptor */
#define	STDOUT_FILENO	1	/* standard output file descriptor */
#define	STDERR_FILENO	2	/* standard error file descriptor */

/* fnmatch(3) defines */
#define	FNM_PATHNAME	0x01	/* match pathnames, not filenames */
#ifndef _POSIX_SOURCE
#define	FNM_QUOTE	0x02	/* escape special chars with \ */
#endif

#ifndef NULL
#define	NULL		0	/* null pointer constant */
#endif

typedef	int ssize_t;		/* count of bytes or error indication */

__BEGIN_DECLS
void volatile	 _exit __P((int));
int		 access __P((const char *, int));
u_int		 alarm __P((u_int));
int		 chdir __P((const char *));
int		 chown __P((const char *, uid_t, gid_t));
int		 close __P((int));
char		*cuserid __P((const char *));
int		 dup __P((int));
int		 dup2 __P((int, int));
int		 execl __P((const char *, const char *, ...));
int		 execle __P((const char *, const char *, ...));
int		 execlp __P((const char *, const char *, ...));
int		 execv __P((const char *, char * const *));
int		 execve __P((const char *, char * const *, char * const *));
int		 execvp __P((const char *, char * const *));
pid_t		 fork __P((void));
long		 fpathconf __P((int, int));		/* not yet */
char		*getcwd __P((char *, size_t));
gid_t		 getegid __P((void));
uid_t		 geteuid __P((void));
gid_t		 getgid __P((void));
int		 getgroups __P((int, gid_t *));
char		*getlogin __P((void));
pid_t		 getpgrp __P((void));
pid_t		 getpid __P((void));
pid_t		 getppid __P((void));
uid_t		 getuid __P((void));
int		 isatty __P((int));
int		 link __P((const char *, const char *));
off_t		 lseek __P((int, off_t, int));
long		 pathconf __P((const char *, int));	/* not yet */
int		 pause __P((void));
int		 pipe __P((int *));
ssize_t		 read __P((int, void *, size_t));
int		 rmdir __P((const char *));
int		 setgid __P((gid_t));
int		 setpgid __P((pid_t, pid_t));
pid_t		 setsid __P((void));
int		 setuid __P((uid_t));
u_int		 sleep __P((u_int));
long		 sysconf __P((int));			/* not yet */
pid_t		 tcgetpgrp __P((int));
pid_t		 tcsetpgrp __P((int, pid_t));
char		*ttyname __P((int));
int		 unlink __P((const char *));
ssize_t		 write __P((int, const void *, size_t));

#ifndef	_POSIX_SOURCE

/* structure timeval required for select() */
#include <sys/time.h>

/* structure qelem required for insque() and remque() */
struct qelem {
	struct	qelem *q_forw;
	struct	qelem *q_back;
	char	q_data[1];	/* arbitrary amount of data */
};

int	 acct __P((const char *));
int	 async_daemon __P((void));
char	*brk __P((const char *));
int	 chflags __P((const char *, long));
int	 chroot __P((const char *));
char	*crypt __P((const char *, const char *));
void	 encrypt __P((char *, int));
void	 endusershell __P((void));
int	 exect __P((const char *, char * const *, char * const *));
int	 fchdir __P((int));
int	 fchflags __P((int, long));
int	 fchmod __P((int, mode_t));
int	 fchown __P((int, int, int));
int	 fnmatch __P((const char *, const char *, int));
int	 fsync __P((int));
int	 ftruncate __P((int, off_t));
int	 getdtablesize __P((void));
long	 gethostid __P((void));
int	 gethostname __P((char *, int));
mode_t	 getmode __P((const mode_t *, mode_t));
int	 getpagesize __P((void));
char	*getpass __P((const char *));
char	*getusershell __P((void));
char	*getwd __P((char *));			/* obsoleted by getcwd() */
int	 initgroups __P((const char *, int));
void	 insque __P((struct qelem *, struct qelem *));
int	 mknod __P((const char *, mode_t, dev_t));
int	 mkstemp __P((char *));
char	*mktemp __P((char *));
int	 nfssvc __P((int));
int	 nice __P((int));
int	 psignal __P((u_int, const char *));
int	 profil __P((char *, int, int, int));
int	 rcmd __P((char **, int, const char *,
		const char *, const char *, int *));
char	*re_comp __P((const char *));
int	 re_exec __P((const char *));
int	 readlink __P((const char *, char *, int));
int	 reboot __P((int));
void	 remque __P((struct qelem *));
int	 revoke __P((const char *));
int	 rresvport __P((const int *));
int	 ruserok __P((const char *, int, const char *, const char *));
char	*sbrk __P((int));
int	 select __P((int, fd_set *, fd_set *, fd_set *, struct timeval *));
int	 setegid __P((gid_t));
int	 seteuid __P((uid_t));
int	 setgroups __P((int, const int *));
void	 sethostid __P((long));
int	 sethostname __P((const char *, int));
void	 setkey __P((const char *));
int	 setlogin __P((const char *));
mode_t	 setmode __P((const char *));
int	 setpgrp __P((pid_t pid, pid_t pgrp));	/* obsoleted by setpgid() */
int	 setregid __P((int, int));
int	 setreuid __P((int, int));
int	 setrgid __P((gid_t));
int	 setruid __P((uid_t));
void	 setusershell __P((void));
int	 swapon __P((const char *));
int	 symlink __P((const char *, const char *));
void	 sync __P((void));
int	 syscall __P((int, ...));
int	 truncate __P((const char *, off_t));
int	 ttyslot __P((void));
u_int	 ualarm __P((u_int, u_int));
void	 usleep __P((u_int));
void	*valloc __P((size_t));			/* obsoleted by malloc() */
int	 vfork __P((void));

#endif /* !_POSIX_SOURCE */
__END_DECLS
