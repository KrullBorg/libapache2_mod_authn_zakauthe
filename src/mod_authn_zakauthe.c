/*
 * Copyright (C) 2017 Andrea Zagli <azagli@libero.it>
 *
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
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "apr_strings.h"

#include "ap_config.h"
#include "ap_provider.h"
#include "httpd.h"
#include "http_config.h"
#include "http_core.h"
#include "http_log.h"
#include "http_protocol.h"
#include "http_request.h"

#include "mod_auth.h"

#ifdef HAVE_CONFIG_H
	#include <config.h>
#endif

#include <libzakauthe/libzakauthe.h>

static authn_status
check_password (request_rec *r, const char *user,
                const char *password)
{
	return AUTH_GRANTED;
}

static authn_status
get_realm_hash (request_rec *r, const char *user,
                const char *realm, char **rethash)
{
	return AUTH_GRANTED;
}

static const authn_provider authn_zakauthe_provider =
	{
		&check_password,
		&get_realm_hash,
	};

static void
register_hooks (apr_pool_t *pool)
{
	ap_register_auth_provider (pool, AUTHN_PROVIDER_GROUP, "zakauthe",
	                           AUTHN_PROVIDER_VERSION,
	                           &authn_zakauthe_provider, AP_AUTH_INTERNAL_PER_CONF);
}

AP_DECLARE_MODULE(authn_zakauthe) =
{
	STANDARD20_MODULE_STUFF,
	NULL,    /* dir config creater */
	NULL,                            /* dir merger --- default is to override */
	NULL,                            /* server config */
	NULL,                            /* merge server config */
	NULL,                 /* command apr_table_t */
	register_hooks                   /* register hooks */
};
