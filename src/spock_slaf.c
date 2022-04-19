#line 1 "spock_slaf.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <dlfcn.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/uio.h>
#include <arpa/inet.h>
#include <assert.h>
#include <time.h>
#include <errno.h>

// colors macro
#define RED "\033[22;31m"
#define YELLOW "\033[01;33m"
#define CYAN "\033[22;36m"
#define GREEN "\033[22;32m"
#define LAST "\033[0m"

// anomalys log file
#define SPOCK_LOG "spock_agressors.log"
// DFA taint analysis rank to match
#define SPOCK_SCORE 4
 
// set zero to stop DEBUG mode
#define SPOCK_BUGVIEW  1
#define SPOCK_DEBUG(x, s...) do { \
 if (!SPOCK_BUGVIEW) { break; } \
 time_t t = time(NULL); \
 char *d = ctime(&t); \
 fprintf(stderr, "\n--- SPOCK DEBUG-START ---\n\n %.*s %s[%d] %s(): \n", \
 (int)strlen(d) - 1, d, __FILE__, \
 __LINE__, __FUNCTION__); \
 fprintf(stderr, x, ## s); \
 fprintf(stderr,"\n\n--- DEBUG-END ---\n"); \
} while (0);
// detect only HTTP anomalys, if set to zero is can be util for AMQ, zeroMQ, gRPC, SMTP, IMAP...
#define SPOCK_ONLY_HTTP 0

// hook rites
#define _CONSTRUCTOR __attribute__((constructor))
#define _DESTRUCTOR __attribute__ ((destructor))
#define SPOCK_LOAD_CALL(var, name) \
	do {\
		const char *err; \
		(var) = dlsym(RTLD_NEXT, (name)); \
		if ((err = dlerror()) != NULL) { \
			fprintf(stderr, "dlsym %s: %s\n", (name), err); \
			exit(EXIT_FAILURE); \
		} \
	} while(0)



struct spock_hook_ctx {
	int logfd;
	int (*SSL_read)(void *ssl, void *buf, int num);
	int (*SSL_get_rfd)(void *ssl);
	int (*SSL_get_wfd)(void *ssl);
};

enum {
  SQLI,XSS,PATHTRAVERSAL,COUNTER,FILTER_END
};

static struct spock_hook_ctx spock_ctx;

void 
spock_write_log (char *str)
{
	int fd = open(SPOCK_LOG, O_CREAT | O_WRONLY | O_APPEND, 0760 ); 
	FILE *arq=NULL;

	
		if (-1 != fd) 
		{

			arq = fdopen(fd, "ax");

				if (arq == NULL) 
				{
					SPOCK_DEBUG("error in filename %s  to open() file:  %s",SPOCK_LOG,strerror(errno));		
				    exit(0);
				}

			fprintf(arq,"%s\n",str); 

				if (fclose(arq) == EOF)
				{
					SPOCK_DEBUG("error in Write() file %s",SPOCK_LOG);
					exit(0);
				}
		} else {

				if (close(fd) == -1) 
				{
					
					SPOCK_DEBUG("error in filename %s  to open() file:  %s",SPOCK_LOG,strerror(errno));		
					exit(0);
				}
		}

	arq=NULL; 

}

volatile void *
spock_burn_mem(volatile void *dst, int c, size_t len) 
{
	volatile char *buf;
   
		for (buf = (volatile char *)dst;  len;  buf[--len] = c);

	return dst;
}

//  Generated DFA
int 
spock_dfa_filter(char** p, char** lex)
{
    char* marker;

    for (;;) {
    *lex = *p;
    
#line 133 "<stdout>"
	{
		char yych;
		yych = (char)**p;
		switch (yych) {
		case '\n':	goto yy4;
		case '*':
		case '>':	goto yy6;
		case '.':	goto yy7;
		case 'a':	goto yy8;
		case 'c':	goto yy9;
		case 'd':	goto yy10;
		case 'e':	goto yy11;
		case 'f':	goto yy12;
		case 'i':	goto yy13;
		case 'j':	goto yy14;
		case 'm':	goto yy15;
		case 'o':	goto yy16;
		case 'p':	goto yy17;
		case 's':	goto yy18;
		case 'u':	goto yy19;
		case 'v':	goto yy20;
		case 'w':	goto yy21;
		default:	goto yy2;
		}
yy2:
		++*p;
yy3:
#line 140 "spock_slaf.c"
		{ continue; }
#line 163 "<stdout>"
yy4:
		++*p;
#line 139 "spock_slaf.c"
		{ return FILTER_END; }
#line 168 "<stdout>"
yy6:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '*':
		case '.':
		case '>':
		case 'a':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'i':
		case 'j':
		case 'm':
		case 'o':
		case 'p':
		case 's':
		case 'u':
		case 'v':
		case 'w':	goto yy23;
		default:	goto yy3;
		}
yy7:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '*':
		case '>':
		case 'a':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'i':
		case 'j':
		case 'm':
		case 'o':
		case 'p':
		case 's':
		case 'u':
		case 'v':
		case 'w':	goto yy23;
		case '.':	goto yy40;
		default:	goto yy3;
		}
yy8:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'l':	goto yy43;
		default:	goto yy3;
		}
yy9:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'o':	goto yy44;
		default:	goto yy3;
		}
yy10:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'e':	goto yy45;
		case 'o':	goto yy46;
		case 'r':	goto yy47;
		default:	goto yy3;
		}
yy11:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 't':	goto yy48;
		case 'v':	goto yy49;
		case 'x':	goto yy50;
		default:	goto yy3;
		}
yy12:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'r':	goto yy51;
		default:	goto yy3;
		}
yy13:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'f':	goto yy52;
		case 'n':	goto yy53;
		default:	goto yy3;
		}
yy14:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'a':	goto yy54;
		default:	goto yy3;
		}
yy15:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'a':	goto yy55;
		default:	goto yy3;
		}
yy16:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'n':	goto yy56;
		default:	goto yy3;
		}
yy17:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'a':	goto yy57;
		default:	goto yy3;
		}
yy18:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'c':	goto yy58;
		case 'e':	goto yy59;
		case 'h':	goto yy60;
		case 'l':	goto yy61;
		default:	goto yy3;
		}
yy19:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'n':	goto yy62;
		default:	goto yy3;
		}
yy20:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'e':	goto yy63;
		default:	goto yy3;
		}
yy21:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'h':	goto yy64;
		default:	goto yy3;
		}
yy22:
		yych = (char)*++*p;
yy23:
		switch (yych) {
		case '*':
		case '>':	goto yy22;
		case '.':	goto yy25;
		case 'a':	goto yy26;
		case 'c':	goto yy27;
		case 'd':	goto yy28;
		case 'e':	goto yy29;
		case 'f':	goto yy30;
		case 'i':	goto yy31;
		case 'j':	goto yy32;
		case 'm':	goto yy33;
		case 'o':	goto yy34;
		case 'p':	goto yy35;
		case 's':	goto yy36;
		case 'u':	goto yy37;
		case 'v':	goto yy38;
		case 'w':	goto yy39;
		default:	goto yy24;
		}
yy24:
		*p = marker;
		goto yy3;
yy25:
		yych = (char)*++*p;
		switch (yych) {
		case '*':
		case '>':	goto yy22;
		case '.':	goto yy40;
		case 'a':	goto yy26;
		case 'c':	goto yy27;
		case 'd':	goto yy28;
		case 'e':	goto yy29;
		case 'f':	goto yy30;
		case 'i':	goto yy31;
		case 'j':	goto yy32;
		case 'm':	goto yy33;
		case 'o':	goto yy34;
		case 'p':	goto yy35;
		case 's':	goto yy36;
		case 'u':	goto yy37;
		case 'v':	goto yy38;
		case 'w':	goto yy39;
		default:	goto yy24;
		}
yy26:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy43;
		default:	goto yy24;
		}
yy27:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy44;
		default:	goto yy24;
		}
yy28:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy45;
		case 'o':	goto yy46;
		case 'r':	goto yy47;
		default:	goto yy24;
		}
yy29:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy48;
		case 'v':	goto yy49;
		case 'x':	goto yy50;
		default:	goto yy24;
		}
yy30:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy51;
		default:	goto yy24;
		}
yy31:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy52;
		case 'n':	goto yy53;
		default:	goto yy24;
		}
yy32:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy54;
		default:	goto yy24;
		}
yy33:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy55;
		default:	goto yy24;
		}
yy34:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy56;
		default:	goto yy24;
		}
yy35:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy57;
		default:	goto yy24;
		}
yy36:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy58;
		case 'e':	goto yy59;
		case 'h':	goto yy60;
		case 'l':	goto yy61;
		default:	goto yy24;
		}
yy37:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy62;
		default:	goto yy24;
		}
yy38:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy63;
		default:	goto yy24;
		}
yy39:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy64;
		default:	goto yy24;
		}
yy40:
		yych = (char)*++*p;
		switch (yych) {
		case '\n':	goto yy42;
		case '*':
		case '.':
		case '>':	goto yy40;
		case 'a':	goto yy67;
		case 'c':	goto yy68;
		case 'd':	goto yy69;
		case 'e':	goto yy70;
		case 'f':	goto yy71;
		case 'i':	goto yy72;
		case 'j':	goto yy73;
		case 'm':	goto yy74;
		case 'o':	goto yy75;
		case 's':	goto yy76;
		case 'u':	goto yy77;
		case 'v':	goto yy78;
		case 'w':	goto yy79;
		default:	goto yy65;
		}
yy42:
#line 138 "spock_slaf.c"
		{ return PATHTRAVERSAL; }
#line 470 "<stdout>"
yy43:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy80;
		default:	goto yy24;
		}
yy44:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy81;
		default:	goto yy24;
		}
yy45:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy82;
		default:	goto yy24;
		}
yy46:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy83;
		default:	goto yy24;
		}
yy47:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy84;
		default:	goto yy24;
		}
yy48:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy65;
		default:	goto yy24;
		}
yy49:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy85;
		default:	goto yy24;
		}
yy50:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy86;
		default:	goto yy24;
		}
yy51:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy87;
		default:	goto yy24;
		}
yy52:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy88;
		default:	goto yy24;
		}
yy53:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy89;
		default:	goto yy24;
		}
yy54:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy90;
		default:	goto yy24;
		}
yy55:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy91;
		case 't':	goto yy92;
		default:	goto yy24;
		}
yy56:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy93;
		case 'e':	goto yy94;
		case 'f':	goto yy95;
		case 'l':	goto yy96;
		case 'm':	goto yy97;
		case 'p':	goto yy98;
		case 's':	goto yy99;
		default:	goto yy24;
		}
yy57:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy100;
		default:	goto yy24;
		}
yy58:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy101;
		default:	goto yy24;
		}
yy59:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy102;
		default:	goto yy24;
		}
yy60:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy103;
		default:	goto yy24;
		}
yy61:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy104;
		default:	goto yy24;
		}
yy62:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy105;
		default:	goto yy24;
		}
yy63:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy106;
		default:	goto yy24;
		}
yy64:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy107;
		default:	goto yy24;
		}
yy65:
		yych = (char)*++*p;
yy66:
		switch (yych) {
		case '\n':	goto yy42;
		default:	goto yy65;
		}
yy67:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy108;
		default:	goto yy66;
		}
yy68:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy109;
		default:	goto yy66;
		}
yy69:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy110;
		case 'o':	goto yy111;
		case 'r':	goto yy112;
		default:	goto yy66;
		}
yy70:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy113;
		case 'x':	goto yy114;
		default:	goto yy66;
		}
yy71:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy115;
		default:	goto yy66;
		}
yy72:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy116;
		case 'n':	goto yy117;
		default:	goto yy66;
		}
yy73:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy118;
		default:	goto yy66;
		}
yy74:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy119;
		default:	goto yy66;
		}
yy75:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy120;
		default:	goto yy66;
		}
yy76:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy121;
		case 'e':	goto yy122;
		case 'l':	goto yy123;
		default:	goto yy66;
		}
yy77:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy124;
		default:	goto yy66;
		}
yy78:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy125;
		default:	goto yy66;
		}
yy79:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy126;
		default:	goto yy66;
		}
yy80:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy127;
		default:	goto yy24;
		}
yy81:
		yych = (char)*++*p;
		switch (yych) {
		case 'k':	goto yy128;
		default:	goto yy24;
		}
yy82:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy129;
		default:	goto yy24;
		}
yy83:
		yych = (char)*++*p;
		switch (yych) {
		case 'u':	goto yy130;
		default:	goto yy24;
		}
yy84:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy131;
		default:	goto yy24;
		}
yy85:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy134;
		default:	goto yy24;
		}
yy86:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy137;
		default:	goto yy24;
		}
yy87:
		yych = (char)*++*p;
		switch (yych) {
		case 'm':	goto yy138;
		default:	goto yy24;
		}
yy88:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy139;
		default:	goto yy24;
		}
yy89:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy140;
		default:	goto yy24;
		}
yy90:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy141;
		default:	goto yy24;
		}
yy91:
		yych = (char)*++*p;
		switch (yych) {
		case 'R':	goto yy142;
		default:	goto yy24;
		}
yy92:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy143;
		default:	goto yy24;
		}
yy93:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy144;
		default:	goto yy24;
		}
yy94:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy145;
		default:	goto yy24;
		}
yy95:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy146;
		default:	goto yy24;
		}
yy96:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy147;
		default:	goto yy24;
		}
yy97:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy148;
		default:	goto yy24;
		}
yy98:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy149;
		case 'r':	goto yy150;
		default:	goto yy24;
		}
yy99:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy151;
		default:	goto yy24;
		}
yy100:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy152;
		default:	goto yy24;
		}
yy101:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy153;
		default:	goto yy24;
		}
yy102:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy154;
		default:	goto yy24;
		}
yy103:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy155;
		default:	goto yy24;
		}
yy104:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy84;
		default:	goto yy24;
		}
yy105:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy156;
		default:	goto yy24;
		}
yy106:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy62;
		default:	goto yy24;
		}
yy107:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy157;
		default:	goto yy24;
		}
yy108:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy158;
		default:	goto yy66;
		}
yy109:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy159;
		default:	goto yy66;
		}
yy110:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy160;
		default:	goto yy66;
		}
yy111:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy161;
		default:	goto yy66;
		}
yy112:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy162;
		default:	goto yy66;
		}
yy113:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy163;
		default:	goto yy66;
		}
yy114:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy164;
		default:	goto yy66;
		}
yy115:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy165;
		default:	goto yy66;
		}
yy116:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy166;
		default:	goto yy66;
		}
yy117:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy167;
		default:	goto yy66;
		}
yy118:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy168;
		default:	goto yy66;
		}
yy119:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy169;
		case 't':	goto yy170;
		default:	goto yy66;
		}
yy120:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy171;
		case 'e':	goto yy172;
		case 'f':	goto yy173;
		case 'l':	goto yy174;
		case 'm':	goto yy175;
		case 'p':	goto yy176;
		case 's':	goto yy177;
		default:	goto yy66;
		}
yy121:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy178;
		default:	goto yy66;
		}
yy122:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy179;
		default:	goto yy66;
		}
yy123:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy180;
		default:	goto yy66;
		}
yy124:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy181;
		default:	goto yy66;
		}
yy125:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy182;
		default:	goto yy66;
		}
yy126:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy183;
		default:	goto yy66;
		}
yy127:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy134;
		default:	goto yy24;
		}
yy128:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy184;
		default:	goto yy24;
		}
yy129:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy157;
		default:	goto yy24;
		}
yy130:
		yych = (char)*++*p;
		switch (yych) {
		case 'm':	goto yy185;
		default:	goto yy24;
		}
yy131:
		yych = (char)*++*p;
		switch (yych) {
		case '\n':	goto yy133;
		default:	goto yy131;
		}
yy133:
#line 136 "spock_slaf.c"
		{ return SQLI; }
#line 1024 "<stdout>"
yy134:
		yych = (char)*++*p;
		switch (yych) {
		case '\n':	goto yy136;
		default:	goto yy134;
		}
yy136:
#line 137 "spock_slaf.c"
		{ return XSS; }
#line 1034 "<stdout>"
yy137:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy186;
		default:	goto yy24;
		}
yy138:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':	goto yy187;
		default:	goto yy24;
		}
yy139:
		yych = (char)*++*p;
		switch (yych) {
		case 'm':	goto yy184;
		default:	goto yy24;
		}
yy140:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy188;
		default:	goto yy24;
		}
yy141:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy189;
		default:	goto yy24;
		}
yy142:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy190;
		default:	goto yy24;
		}
yy143:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy131;
		default:	goto yy24;
		}
yy144:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy191;
		default:	goto yy24;
		}
yy145:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy192;
		default:	goto yy24;
		}
yy146:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy193;
		default:	goto yy24;
		}
yy147:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy194;
		default:	goto yy24;
		}
yy148:
		yych = (char)*++*p;
		switch (yych) {
		case 'u':	goto yy195;
		default:	goto yy24;
		}
yy149:
		yych = (char)*++*p;
		switch (yych) {
		case 'g':	goto yy196;
		default:	goto yy24;
		}
yy150:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy197;
		default:	goto yy24;
		}
yy151:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy80;
		default:	goto yy24;
		}
yy152:
		yych = (char)*++*p;
		switch (yych) {
		case 'w':	goto yy198;
		default:	goto yy24;
		}
yy153:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy127;
		default:	goto yy24;
		}
yy154:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy188;
		default:	goto yy24;
		}
yy155:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy199;
		default:	goto yy24;
		}
yy156:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy131;
		default:	goto yy24;
		}
yy157:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy131;
		default:	goto yy24;
		}
yy158:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy200;
		default:	goto yy66;
		}
yy159:
		yych = (char)*++*p;
		switch (yych) {
		case 'k':	goto yy201;
		default:	goto yy66;
		}
yy160:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy202;
		default:	goto yy66;
		}
yy161:
		yych = (char)*++*p;
		switch (yych) {
		case 'u':	goto yy203;
		default:	goto yy66;
		}
yy162:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy131;
		default:	goto yy66;
		}
yy163:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy134;
		default:	goto yy66;
		}
yy164:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy204;
		default:	goto yy66;
		}
yy165:
		yych = (char)*++*p;
		switch (yych) {
		case 'm':	goto yy205;
		default:	goto yy66;
		}
yy166:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy206;
		default:	goto yy66;
		}
yy167:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy207;
		default:	goto yy66;
		}
yy168:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy208;
		default:	goto yy66;
		}
yy169:
		yych = (char)*++*p;
		switch (yych) {
		case 'R':	goto yy209;
		default:	goto yy66;
		}
yy170:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy210;
		default:	goto yy66;
		}
yy171:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy211;
		default:	goto yy66;
		}
yy172:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy212;
		default:	goto yy66;
		}
yy173:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy213;
		default:	goto yy66;
		}
yy174:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy214;
		default:	goto yy66;
		}
yy175:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy215;
		default:	goto yy66;
		}
yy176:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy216;
		case 'r':	goto yy217;
		default:	goto yy66;
		}
yy177:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy218;
		default:	goto yy66;
		}
yy178:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy219;
		default:	goto yy66;
		}
yy179:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy220;
		default:	goto yy66;
		}
yy180:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy162;
		default:	goto yy66;
		}
yy181:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy221;
		default:	goto yy66;
		}
yy182:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy124;
		default:	goto yy66;
		}
yy183:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy222;
		default:	goto yy66;
		}
yy184:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy134;
		default:	goto yy24;
		}
yy185:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy223;
		default:	goto yy24;
		}
yy186:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy224;
		default:	goto yy24;
		}
yy187:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy225;
		default:	goto yy24;
		}
yy188:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy131;
		default:	goto yy24;
		}
yy189:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy58;
		default:	goto yy24;
		}
yy190:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy226;
		default:	goto yy24;
		}
yy191:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy227;
		default:	goto yy24;
		}
yy192:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy228;
		default:	goto yy24;
		}
yy193:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy229;
		default:	goto yy24;
		}
yy194:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy134;
		default:	goto yy24;
		}
yy195:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy230;
		default:	goto yy24;
		}
yy196:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy231;
		default:	goto yy24;
		}
yy197:
		yych = (char)*++*p;
		switch (yych) {
		case 'g':	goto yy232;
		default:	goto yy24;
		}
yy198:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy233;
		default:	goto yy24;
		}
yy199:
		yych = (char)*++*p;
		switch (yych) {
		case 'w':	goto yy65;
		default:	goto yy24;
		}
yy200:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy134;
		default:	goto yy66;
		}
yy201:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy234;
		default:	goto yy66;
		}
yy202:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy222;
		default:	goto yy66;
		}
yy203:
		yych = (char)*++*p;
		switch (yych) {
		case 'm':	goto yy235;
		default:	goto yy66;
		}
yy204:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy236;
		default:	goto yy66;
		}
yy205:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':	goto yy237;
		default:	goto yy66;
		}
yy206:
		yych = (char)*++*p;
		switch (yych) {
		case 'm':	goto yy234;
		default:	goto yy66;
		}
yy207:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy238;
		default:	goto yy66;
		}
yy208:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy239;
		default:	goto yy66;
		}
yy209:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy240;
		default:	goto yy66;
		}
yy210:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy131;
		default:	goto yy66;
		}
yy211:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy241;
		default:	goto yy66;
		}
yy212:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy242;
		default:	goto yy66;
		}
yy213:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy243;
		default:	goto yy66;
		}
yy214:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy244;
		default:	goto yy66;
		}
yy215:
		yych = (char)*++*p;
		switch (yych) {
		case 'u':	goto yy245;
		default:	goto yy66;
		}
yy216:
		yych = (char)*++*p;
		switch (yych) {
		case 'g':	goto yy246;
		default:	goto yy66;
		}
yy217:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy247;
		default:	goto yy66;
		}
yy218:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy158;
		default:	goto yy66;
		}
yy219:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy200;
		default:	goto yy66;
		}
yy220:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy238;
		default:	goto yy66;
		}
yy221:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy131;
		default:	goto yy66;
		}
yy222:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy131;
		default:	goto yy66;
		}
yy223:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy127;
		default:	goto yy24;
		}
yy224:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy248;
		default:	goto yy24;
		}
yy225:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy249;
		default:	goto yy24;
		}
yy226:
		yych = (char)*++*p;
		switch (yych) {
		case 'u':	goto yy250;
		default:	goto yy24;
		}
yy227:
		yych = (char)*++*p;
		switch (yych) {
		case 'k':	goto yy134;
		default:	goto yy24;
		}
yy228:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy134;
		default:	goto yy24;
		}
yy229:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy251;
		default:	goto yy24;
		}
yy230:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy252;
		default:	goto yy24;
		}
yy231:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy253;
		default:	goto yy24;
		}
yy232:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy254;
		default:	goto yy24;
		}
yy233:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy255;
		default:	goto yy24;
		}
yy234:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy134;
		default:	goto yy66;
		}
yy235:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy256;
		default:	goto yy66;
		}
yy236:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy257;
		default:	goto yy66;
		}
yy237:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy258;
		default:	goto yy66;
		}
yy238:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy131;
		default:	goto yy66;
		}
yy239:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy121;
		default:	goto yy66;
		}
yy240:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy259;
		default:	goto yy66;
		}
yy241:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy260;
		default:	goto yy66;
		}
yy242:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy261;
		default:	goto yy66;
		}
yy243:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy262;
		default:	goto yy66;
		}
yy244:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy134;
		default:	goto yy66;
		}
yy245:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy263;
		default:	goto yy66;
		}
yy246:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy264;
		default:	goto yy66;
		}
yy247:
		yych = (char)*++*p;
		switch (yych) {
		case 'g':	goto yy265;
		default:	goto yy66;
		}
yy248:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy266;
		default:	goto yy24;
		}
yy249:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy267;
		default:	goto yy24;
		}
yy250:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy157;
		default:	goto yy24;
		}
yy251:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy134;
		default:	goto yy24;
		}
yy252:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy268;
		default:	goto yy24;
		}
yy253:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy269;
		default:	goto yy24;
		}
yy254:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy270;
		default:	goto yy24;
		}
yy255:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy65;
		default:	goto yy24;
		}
yy256:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy200;
		default:	goto yy66;
		}
yy257:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy271;
		default:	goto yy66;
		}
yy258:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy272;
		default:	goto yy66;
		}
yy259:
		yych = (char)*++*p;
		switch (yych) {
		case 'u':	goto yy273;
		default:	goto yy66;
		}
yy260:
		yych = (char)*++*p;
		switch (yych) {
		case 'k':	goto yy134;
		default:	goto yy66;
		}
yy261:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy134;
		default:	goto yy66;
		}
yy262:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy274;
		default:	goto yy66;
		}
yy263:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy275;
		default:	goto yy66;
		}
yy264:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy276;
		default:	goto yy66;
		}
yy265:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy277;
		default:	goto yy66;
		}
yy266:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy278;
		default:	goto yy24;
		}
yy267:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':	goto yy279;
		default:	goto yy24;
		}
yy268:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy280;
		default:	goto yy24;
		}
yy269:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy281;
		default:	goto yy24;
		}
yy270:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy282;
		default:	goto yy24;
		}
yy271:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy283;
		default:	goto yy66;
		}
yy272:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy284;
		default:	goto yy66;
		}
yy273:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy222;
		default:	goto yy66;
		}
yy274:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy134;
		default:	goto yy66;
		}
yy275:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy285;
		default:	goto yy66;
		}
yy276:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy286;
		default:	goto yy66;
		}
yy277:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy287;
		default:	goto yy66;
		}
yy278:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy134;
		default:	goto yy24;
		}
yy279:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy288;
		default:	goto yy24;
		}
yy280:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy228;
		default:	goto yy24;
		}
yy281:
		yych = (char)*++*p;
		switch (yych) {
		case 'w':	goto yy134;
		default:	goto yy24;
		}
yy282:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy134;
		default:	goto yy24;
		}
yy283:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy289;
		default:	goto yy66;
		}
yy284:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':	goto yy290;
		default:	goto yy66;
		}
yy285:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy291;
		default:	goto yy66;
		}
yy286:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy292;
		default:	goto yy66;
		}
yy287:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy293;
		default:	goto yy66;
		}
yy288:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy184;
		default:	goto yy24;
		}
yy289:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy134;
		default:	goto yy66;
		}
yy290:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy294;
		default:	goto yy66;
		}
yy291:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy261;
		default:	goto yy66;
		}
yy292:
		yych = (char)*++*p;
		switch (yych) {
		case 'w':	goto yy134;
		default:	goto yy66;
		}
yy293:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy134;
		default:	goto yy66;
		}
yy294:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy234;
		default:	goto yy66;
		}
	}
#line 141 "spock_slaf.c"

    }
}


/* #times substr appears in s, no overlaps */
int 
spock_counter_matchs(const char *s, const char *substr)
{
    int n = 0;
    const char *p = s;

    size_t lenSubstr = strlen(substr);

	    while (*p) 
	    {
	        if (memcmp(p, substr, lenSubstr) == 0) 
	        {
	            ++n;
	            p += lenSubstr;
	        } else 
	            ++p;
	    }

    return n;
}


int 
spock_score_sqli(char *input)
{
	int total_list = 0;
	int score = 0, i = 0;
	
	const char *list[] = 
	{
		"insert","union","where","sleep","delete","mapreduce","timeout","@version","db.injection","/**/"
	};

	total_list = sizeof(list) / sizeof(list[0]);

		while(i!=total_list)
		{
			score+=spock_counter_matchs(input,list[i]);
			i++;
			if(SPOCK_SCORE<=score)
				return score;
		}

	return score;
}

int 
spock_score_pathtraversal(char *input)
{
	int total_list = 0;
	int score = 0, i = 0;
	const char *list[] = 
	{
		"..","\\\\","//","...","shadow","etc","password"
	};

	total_list = sizeof(list) / sizeof(list[0]);

		while(i!=total_list)
		{
			score+=spock_counter_matchs(input,list[i]);
			i++;
				if(SPOCK_SCORE<=score)
					return score;
		}

	return score;
}

int 
spock_score_xss(char *input)
{
	int total_list = 0;
	int score = 0, i = 0;
	const char *list[] = 
	{
		"eval","script","javascript","document","cookie","onstart","onerror","onpageshow","onprogress","alert","onclick","onmouseover","onfinish","fromChar","iframe"
	};

	total_list = sizeof(list) / sizeof(list[0]);

		while(i!=total_list)
		{
			score+=spock_counter_matchs(input,list[i]);
			i++;
				if(SPOCK_SCORE<=score)
					return score;
		}

	return score;
}


int
spock_dfa_check(char *input)
{

    char *last = input;


		switch (spock_dfa_filter(&input, &last)) 
		{
			case SQLI:
			return 1;
			break;

			case XSS:
			return 2;
			break;

			case PATHTRAVERSAL:
			return 3;
			break;
			  
			case FILTER_END:
			return 0;	
			break;
		}

	return 0;

}


// jack the ripper function 
// func to split request in chunks, util because a lot functions cannot match request buffer in full mode
bool 
split_and_check (char * input,  int (*lambda)(char *argvs))
{
	int option = 0;
	char *delim = "\n";
	char *ptr = strtok(input, delim);
	int score=0;

		while (ptr != NULL)
		{
			option = lambda(ptr);
			ptr = strtok(NULL, delim);

				switch (option)
				{

					case 1:
					score=spock_score_sqli(input);
						if(score >= SPOCK_SCORE)
						{
	        					spock_write_log("Attack type: SQl injection\n");
							return true;
						}
				    	break;

					case 2:
					score=spock_score_xss(input);
						if(score >= SPOCK_SCORE)
						{
	        				spock_write_log("Attack type: XSS\n");
							return true;
						}
				   	break;

					case 3:
					score=spock_score_pathtraversal(input);
						if(score >= SPOCK_SCORE)
						{
	        				spock_write_log("Attack type: path traversal\n");
							return true;
						}
					break;
				  
				}
				
		}
		



	return false;

}


// Deterministic Finite Automata to check if letter exist between a-z or A-Z
// generated by flex+bison
int 
spock_test_letter(char p)
{
	unsigned char yych;

	yych = p;
	switch (yych) 
	{
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	
				++p;
				return 0;
		default:	
				return 1; 
	}   

}

void 
_CONSTRUCTOR hook_init(void) 
{
	spock_ctx.logfd = open(SPOCK_LOG, O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);

		if (spock_ctx.logfd < 0) 
		{
			SPOCK_DEBUG("Unable to create %s",SPOCK_LOG);
			exit(0);
		}

	dlerror();
	SPOCK_LOAD_CALL(spock_ctx.SSL_read, "SSL_read");
	SPOCK_LOAD_CALL(spock_ctx.SSL_get_rfd, "SSL_get_rfd");
	SPOCK_LOAD_CALL(spock_ctx.SSL_get_wfd, "SSL_get_wfd");
}


void 
_DESTRUCTOR hook_end(void) 
{
	close(spock_ctx.logfd);
}



static void *
spock_xmalloc_fatal(size_t size) 
{

	SPOCK_DEBUG("\n Memory FAILURE...\n size dbg: %zu\n",size);

	exit(0);
}


void *
spock_xmalloc (size_t size) 
{
	void *ptr = malloc (size);

		if (ptr == NULL) 
			return spock_xmalloc_fatal(size);

	return ptr;
}


void *
spock_xrealloc(void *ptr, size_t size)
{
	ptr = realloc(ptr, size);

		if (!ptr) 
		{
			SPOCK_DEBUG("realloc failed: %s", strerror(errno));
			exit(0);
		}
	return ptr;
}


// Fork of OpenBSD's function
/*
 * This is sqrt(SIZE_MAX+1), as s1*s2 <= SIZE_MAX
 * if both s1 < MUL_NO_OVERFLOW and s2 < MUL_NO_OVERFLOW
 */
#define SPOCK_MUL_NO_OVERFLOW	((size_t)1 << (sizeof(size_t) * 4))

void *
spock_reallocarray(void *optr, size_t nmemb, size_t size)
{
		if ((nmemb >= SPOCK_MUL_NO_OVERFLOW || size >= SPOCK_MUL_NO_OVERFLOW) &&
		    nmemb > 0 && SIZE_MAX / nmemb < size) 
		{
			errno = ENOMEM;
			return NULL;
		}
	return spock_xrealloc(optr, size * nmemb);
}

// Fork of OpenBSD's function
void *
spock_xmallocarray(size_t num, size_t size)
{
	void *result = spock_reallocarray(NULL, num, size);

        if (!result) 
        {
            SPOCK_DEBUG("reallocarray failed: %s", strerror(errno));
            exit(0);
        }

	return result;
}


char *
all2lowcase(char *str) 
{
	char *str_new=spock_xmallocarray(sizeof(char),strlen(str)+1);
	int i=0;
	
		while(*str != '\0')
		{
			// Deterministic Finite Automata to check letter and case 
				if(!spock_test_letter( *str ) )
				{
					*(str_new+i)=*str | 0x20;	
					i++;
				} else {
					*(str_new+i)=*str;
					i++;
				}


			str++;	
		}


	return str_new;

}


char *
spock_get_ip_str(struct sockaddr *sa, char *s, size_t maxlen)
{
	    switch(sa->sa_family) 
	    {
	        case AF_INET:
	            inet_ntop(AF_INET, &(((struct sockaddr_in *)sa)->sin_addr),
	                    s, maxlen);
	            break;

	        case AF_INET6:
	            inet_ntop(AF_INET6, &(((struct sockaddr_in6 *)sa)->sin6_addr),
	                    s, maxlen);
	            break;

	        default:
	            strncpy(s, "Unknown AF", maxlen);
	            return NULL;
	    }

    return s;
}

bool 
spock_is_request(char *ptr)
{
		if(ptr == NULL)
			return false;

		if(ptr[0]==' ')
			return false;

		if(ptr[1]==' ')
			return false;

		if(strnlen(ptr,12) < 10)
			return false;

	// So don't use strcmp() or strncmp() at this point. These functions are not thread-safe. Keep it like this:
	// is GET ?
	 	if(ptr[0]=='G' && ptr[1]=='E' && ptr[2]=='T')
			return true;

	// is POST ?
	 	if(ptr[0]=='P' && ptr[1]=='O' && ptr[2]=='S' && ptr[3]=='T')
			return true;

	// is PUT ?
	 	if(ptr[0]=='P' && ptr[1]=='U' && ptr[2]=='T')
			return true;

	// is DELETE?
	 	if(ptr[0]=='D' && ptr[1]=='E' && ptr[2]=='L' && ptr[3]=='E' && ptr[4]=='T' && ptr[5]=='E')
			return true;

	return false;
}

/*-strnstr() function
 * Copyright (c) 2001 Mike Barcroft <mike@FreeBSD.org>
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.*/
char *spock_strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

		if ((c = *find++) != '\0') 
		{
			len = strlen(find);

				do {
					do {
						if (slen-- < 1 || (sc = *s++) == '\0')
							return (NULL);
					} while (sc != c);
					if (len > slen)
						return (NULL);
				} while (strncmp(s, find, len) != 0);

			s--;
		}

	return ((char *)s);
}



bool spock_check_block(char *input, int num)
{
	int total_list = 0, total_shellcodes = 0, i = 0;

// use  this point for your custom list of shellcode to block.

#if UINTPTR_MAX == 0xffffffffffffffff
	const char *custom_shellcode[] = 
	{
		"\\x48\\x31\\xc0",                    // xor    rax,rax  X64 LINUX
		"\\x48\\x31\\xdb",                    // xor    rbx,rbx  X64 LINUX
	    	"\\x48\\x31\\xff",                    // xor    rdi,rdi  X64 LINUX
	    	"\\x48\\x31\\xf6",                    // xor    rsi,rsi  X64 LINUX
	    	"\\x48\\x31\\xd2",                    // xor    rdx,rdx  X64 LINUX
	    	"\\x48\\x89\\xe6",                    // mov    rsp,rsi  x64 LINUX 
	    	"\\x48\\x89\\xe7"                    // mov    rsp,rdi  x64 LINUX
	};
#elif UINTPTR_MAX == 0xffffffff	
	const char *custom_shellcode[] = 
	{
		"\\x31\\xc0",                         // xor    eax,eax  x32 LINUX
	    	"\\x31\\xc9",                         // xor    ecx,ecx  X32 LINUX
	    	"\\x31\\xdb",                         // xor    ebx,ebx  x32 LINUX
	    	"\\x31\\xd2",                         // xor    edx,edx  X32 LINUX
	    	"\\x89\\xe1",                         // mov    esp,ecx  x32 LINUX
	    	"\\x89\\xe3"                         // mov    esp,ebx  X32 LINUX
	};
#endif
	// ARM, MIPS in the future -- TODO


// generic payloads to block

	const char *list[] = 
	{
		"\\x90\\x90", // block NOP
		"\\x00\\x00", // nullbyte
		"\\xcd\\x80", // int $0x80 
		"\\xff\\xff",
		"/usr/bin",
		"%s%s%s%s",  // format string...
		"%u%u%u",
		"%x%x%x",
		"%d%d%d",
		"%2e%2e%2f%2e%2e%2f",
		"%252e%252e%252f",
		"%c0%ae",
		"%uff0e%uff0e",
		"0x80000000", // integer overflow maybe
		"0xffffffff",
		"<!--#echo var=",
		"<!--#exec cmd=",
		"autofillupload", // XXE
		"entity xxe",
		"///"
	};

    // prepare context filter
	char *prepared_input=all2lowcase(input);

	total_list = sizeof(list) / sizeof(list[0]);
	total_shellcodes = sizeof(custom_shellcode) / sizeof(custom_shellcode[0]);

	// Test SQL injection/ path traversal/ XSS following  using taint analysis + score based
		if (split_and_check(prepared_input,spock_dfa_check)==true)
		{
				free(prepared_input);
				prepared_input=NULL;
				return true;
		}

		while(i!=total_shellcodes)
		{
			if(spock_strnstr(prepared_input, custom_shellcode[i],num))
			{
				free(prepared_input);
				prepared_input=NULL;
				spock_write_log("Attack type: Buffer overflow\n");
				return true;
			}
			i++;
		}

	i = 0;

		while(i!=total_list)
		{
			if(spock_strnstr(prepared_input, list[i],num))
			{

				free(prepared_input);
				prepared_input=NULL;
				spock_write_log("Attack type: Anomaly\n");
				return true;
			}
			i++;
		}


	free(prepared_input);
	return false;
}



bool spock_detect_anomaly( int fd, void *buf, int num) 
{
	struct sockaddr addr;
	socklen_t addrlen = sizeof(struct sockaddr);


		if (getpeername(fd, &addr, &addrlen) < 0) 
		{
			SPOCK_DEBUG("getpeername error\n");
			exit(0);
		}

		if(SPOCK_BUGVIEW==1)
			printf("\n%s---> SPOCK DEBUG MODE <-========\n%s\n=======-> end DEBUG MODE\n%s",CYAN,(char *)buf,LAST);

    	if(SPOCK_ONLY_HTTP==1)
    	{
    		if(spock_is_request((char *)buf)==false)
    			return false;
    	}


		if(spock_check_block((char *)buf,num)==true)
		{
			int lenmax=(num+128+128)*sizeof(char);
			char *attacker_ip=spock_xmallocarray(129,sizeof(char));
			char *log_line=spock_xmallocarray(lenmax,sizeof(char));
			time_t rawtime = time(NULL);
			struct tm *ptm = localtime(&rawtime);

			spock_burn_mem(attacker_ip,0,128); // save one byte for canary, if you compile with full hardening argvs
			spock_get_ip_str(&addr,attacker_ip,128);	
			spock_burn_mem(log_line,0,lenmax-1);
	 		snprintf(log_line,lenmax-1,"Attacker IP: %s\ndatetime: %02d:%02d:%02d\n===\n%s\n===\n",attacker_ip,ptm->tm_hour,ptm->tm_min, ptm->tm_sec,(char *)buf);

				if(SPOCK_BUGVIEW==1)
					printf("\n%s---> SPOCK DEBUG MODE <-========\n%s\n=======-> end DEBUG MODE\n%s",RED,log_line,LAST);
			
			// write log
	        	spock_write_log(log_line);

	        	// free HEAP 
			free(attacker_ip);
			free(log_line);
			attacker_ip=NULL;
			log_line=NULL;

	        return true;
		}


	return false;
}


int 
SSL_read(void *ssl, void *buf, int num) 
{
	int fd, ret;
	ret = spock_ctx.SSL_read(ssl, buf, num);

		if (ssl != NULL && buf != NULL && ret > 0) 
		{
			fd = spock_ctx.SSL_get_rfd(ssl);

			if (fd < 0) 
			{
				fprintf(stderr, "SSL_get_rfd error\n");
				exit(EXIT_FAILURE);
			}

			if(spock_detect_anomaly(fd, buf, ret)==true)
			{
				// SSL_free(ssl); it's a good try if you detect any memory leak
				return 0;
			}
		}

	return ret;
}


