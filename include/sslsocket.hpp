/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  In addition, as a special exception, the copyright holders give
 *  permission to link the code of portions of this program with the
 *  OpenSSL library under certain conditions as described in each
 *  individual source file, and distribute linked combinations including
 *  the two.
 *
 *  You must obey the GNU General Public License in all respects for all
 *  of the code used other than OpenSSL.  If you modify file(s) with
 *  this exception, you may extend this exception to your version of the
 *  file(s), but you are not obligated to do so.  If you do not wish to
 *  do so, delete this exception statement from your version.  If you
 *  delete this exception statement from all source files in the
 *  program, then also delete it here.
 *
 *  Author : Gundu RAO - 16 Jul 2004
 *           From Hewlett Packard Company.
 */
#ifndef __SSLSOCKET__
#define __SSLSOCKET__

#ifdef USE_OPENSSL
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/ssl.h>
#include <openssl/x509v3.h>
#include <pthread.h>
#endif

/* Initialises an SSL context and makes the lib thread safe */

int TLS_init();

enum tls_init_status {
    TLS_INIT_NORMAL, /* 0   Normal completion    */
    TLS_INIT_ERROR   /* 1   Unspecified error    */
};

enum tls_init_status TLS_init_context(void);

/* Helpers for OpenSSL */

#ifdef USE_OPENSSL
SSL* SSL_new_client();
SSL* SSL_new_server();
const char *SSL_error_string(SSL *ssl, int size);
#endif

#endif
