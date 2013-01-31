#ifndef COOKIES_H
#define COOKIES_H

#include <vpn.h>

struct __attribute__ ((__packed__)) stored_cookie_st {
	char username[MAX_USERNAME_SIZE];
	uint8_t master_secret[TLS_MASTER_SIZE];
	uint8_t session_id[GNUTLS_MAX_SESSION_ID];
	time_t expiration;
};

int store_cookie(const struct cfg_st *, const void* cookie, unsigned cookie_size, 
 		 const struct stored_cookie_st* sc);
void expire_cookies(const struct cfg_st *cfg);

int retrieve_cookie(const struct cfg_st *, const void* cookie, unsigned cookie_size, 
			struct stored_cookie_st* sc);

#endif
