all-local: module

module: mod_authn_zakauthe.c
		if test "$(srcdir)" != "."; then $(CP) $(srcdir)/mod_authn_zakauthe.c .; fi
		$(APXS) -c -D_REENTRANT `echo $(GCC_WARN_FLAGS) | sed 's/ -/ -Wc,-/g'` mod_authn_zakauthe.c

install-exec-local: module
		mkdir -p "$(DESTDIR)`$(APXS) -q LIBEXECDIR`"
		$(APXS) -S LIBEXECDIR="$(DESTDIR)`$(APXS) -q LIBEXECDIR`" -i mod_authn_zakauthe.la

install-exec-hook:
		test -z "$(STRIP)" || $(STRIP) $(DESTDIR)`$(APXS) -q LIBEXECDIR`/mod_authn_zaktueh.so

CLEANFILES=         *.la *.lo *.o *.so *.slo .libs/*

EXTRA_DIST=         CHANGES LICENSE mod_authn_zakauthe.c
