all-local: module

module: mod_authn_zakauthe.c
		if test "$(srcdir)" != "."; then $(CP) $(srcdir)/mod_authn_zakauthe.c .; fi
		$(APXS) -c `echo $(MOD_AUTHN_ZAKAUTHE_CFLAGS) $(MOD_AUTHN_ZAKAUTHE_LIBS) | sed 's/-pthread//g'` mod_authn_zakauthe.c

install-exec-local: module
		mkdir -p "$(DESTDIR)`$(APXS) -q LIBEXECDIR`"
		$(APXS) -S LIBEXECDIR="$(DESTDIR)`$(APXS) -q LIBEXECDIR`" -i `echo $(MOD_AUTHN_ZAKAUTHE_CFLAGS) $(MOD_AUTHN_ZAKAUTHE_LIBS) | sed 's/-pthread//g'` mod_authn_zakauthe.la

install-exec-hook:
		test -z "$(STRIP)" || $(STRIP) $(DESTDIR)`$(APXS) -q LIBEXECDIR`/mod_authn_zaktueh.so

CLEANFILES=         *.la *.lo *.o *.so *.slo .libs/*

EXTRA_DIST=         CHANGES LICENSE mod_authn_zakauthe.c
